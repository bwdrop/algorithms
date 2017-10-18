#include <vector>
#include <string>
#include <random>
#include <iostream>
#include <algorithm>

#include <boost/program_options.hpp>

#include "Bubble.hpp"
#include "Selection.hpp"
#include "Insertion.hpp"
#include "Merge.hpp"
#include "Quick.hpp"

#include "Factory.hpp"

namespace po = boost::program_options;

template <typename T>
void printList(T const &list)
{
  for (typename T::const_iterator it = list.cbegin(); it != list.cend(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

template <typename T>
T randomizeArray(typename T::value_type count) {
  T array;
  std::random_device rd;
  std::mt19937 g(rd());

  for (typename T::value_type i = 1; i < count + 1; ++i)
    array.insert(array.cend(), i);
  std::shuffle(array.begin(), array.end(), g);
  return array;
}

Factory<Sort::ASort<std::vector<int>>> initFactory()
{
  Factory<Sort::ASort<std::vector<int>>> factory;

  factory.record("bubble", &Sort::Bubble<std::vector<int>>::clone);
  factory.record("selection", &Sort::Selection<std::vector<int>>::clone);
  factory.record("insertion", &Sort::Insertion<std::vector<int>>::clone);
  factory.record("merge", &Sort::Merge<std::vector<int>>::clone);
  factory.record("quick", &Sort::Quick<std::vector<int>>::clone);
  return factory;
}

int run(std::string const &algorithm, int nb) {
  Factory<Sort::ASort<std::vector<int>>> factory = initFactory();
  Sort::ASort<std::vector<int>> *sorter = factory.create(algorithm);
  if (sorter)
  {
    std::vector<int> container = randomizeArray<std::vector<int>>(nb);

    std::cout << "Using " << algorithm << " sort on " << nb << " elements.\n";
    printList<std::vector<int>>(container);
    sorter->sort(container);
    delete sorter;
    printList<std::vector<int>>(container);
    container.clear();
    return 0;
  }
  std::cerr << "No such sorting algorithm: " << algorithm << ".\n";
  return 1;
}

int runArgs(char *progName, po::options_description const &desc,
            po::variables_map const &vm)
{
  if (vm.count("help"))
  {
    std::cout << "Usage: " << progName << " [options] algorithm\n";
    std::cout << desc << "\n";
    return 0;
  }
  else if (vm.count("number") && vm.count("type"))
  {
    return run(vm["type"].as<std::string>(), vm["number"].as<int>());
  }
  else
  {
    std::cout << "Invalid options, see help.\n";
  }
  return 1;
}

int parseArgs(int argc, char **argv)
{
  // Generic options
  po::options_description generic("Allowed options");
  generic.add_options()
    ("help,h", "print help message and exit")
    ("number,n", po::value<int>()->default_value(100), "number of elements to sort")
  ;
  // Hidden options
  po::options_description hidden("Hidden options");
  hidden.add_options()
    ("type", po::value<std::string>(), "type of algorithm")
  ;

  po::options_description cmdline_options;
  cmdline_options.add(generic).add(hidden);
  po::positional_options_description p;
  p.add("type", -1);

  po::variables_map vm;
  store(po::command_line_parser(argc, argv).
  options(cmdline_options).positional(p).run(), vm);
  notify(vm);

  return runArgs(argv[0], generic, vm);
}

int main(int argc, char **argv)
{
  try
  {
    return parseArgs(argc, argv);
  }
  catch (std::exception& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
  }
  catch (...)
  {
    std::cerr << "Exception of unknown type!\n";
  }
  return 1;
}
