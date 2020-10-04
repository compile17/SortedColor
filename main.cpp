/*
 * На вход дан неупорядоченный набор объектов, каждый из которых помечен одним из цветов: красный, зеленый и синий.
 * Также на вход дается правило, устанавливающее отношение порядка между цветами.
 * Требуется упорядочить массив в соответствии с указанным правилом.
*/

#include "Work.h"

#include <thread>
#include <future>

using namespace std;

int main()
{
    std::string rule;
    std::unordered_map<char, std::string> container;
    bool reverse;

entering_rule:
    std::cout << "Enter the rule: \n";
    std::cin >> rule;
    std::string ans;
    if (!Work::correctRule(rule, container, reverse)) {
        std::cout << "You entered bad rule!\n"
                  << "Do you want repeat? [y\n]: \n";
        std::cin >> ans;
        if (ans == "y") goto entering_rule;
        else return 0;
    }

    std::string generated;
    bool stop = true;
    auto futureTask = std::async(std::launch::async, Work::generateSequense, std::ref(rule), std::ref(stop));

generate:
    std::cout << "If you want stop generate, you may write \"stop\": ";
    std::cin >> ans;
    if (ans == "stop") {
        stop = false;
        generated = futureTask.get();
        std::cout << "Generated sequence: " << generated << '\n';
    } else goto generate;

    Work::processing(std::move(generated), std::move(rule), std::move(container), reverse);

    return 0;
}
