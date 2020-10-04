#include "Work.h"

// Функция проверки правильности введенного правила
// str - строка с правилом
// cont - контейнер для формирования ключей
// rev - флаг, показывающий направление сортировки (для '<' == true)
bool Work::correctRule(std::string& str, std::unordered_map<char, std::string>& cont, bool& rev) noexcept
{
    int count = 0;
    int reverse = 0;

    auto size = str.size();
    for (auto i = 0; i < size; ++i) {
        // проверка что каждый второй символ, начиная с 0, в правиле - буква
        if (!(i%2)) {
            if (isalpha(str[i])) {
                cont[str[i]] = std::string{""};
                continue;
            }
            else return false;
        }

        // проверка на символ сравнения между буквами
        if (str[i] != '<' && str[i] != '>') return false;
        else {
            if (str[i] == '<') ++count;
            else ++reverse;
        }

        // проверка на зеркальные символы сравнения
        if (reverse && count) return false;
    }

    // удаление символов сравнения
    if (reverse) {
        rev = true;
        str.erase(std::remove(str.begin(), str.end(), '>'), str.end());
    } else
        str.erase(std::remove(str.begin(), str.end(), '<'), str.end());

    // проверка на повторяющиеся буквы
    if (cont.size() != str.size()) return false;

    return true;
}

// Функция упорядочевания набора обьектов
// str - неупорядоченный набор объектов
// rule - правило упорядочевания
// cont - контейнер для упорядочевания
// reverse - флаг, показывающий направление сортировки
std::string Work::processing(std::string&& str, std::string&& rule, std::unordered_map<char, std::string>&& cont, bool reverse) noexcept
{
    // Заполнение контейнера
    for (auto&& ch : str){
        if (cont.find(ch) != cont.end())
            cont[ch].push_back(std::move(ch));
        else return std::string{""};
    }

    // Формирование результирующей строки
    std::string res;
    if (reverse)
        for (auto iter = rule.rbegin(); iter != rule.rend(); ++iter)
            res.append(cont[*iter]);
    else
        for (const auto& ch : rule)
            res.append(cont[ch]);

    std::cout << "\nOrderly sequence: " << res << '\n';

    return res;
}

// Функция генерации набора объектов
// tmp - правило, буквы которого используются при генерации
// stop - флаг остановки генерации
std::string Work::generateSequense(std::string& tmp, bool& stop) noexcept
{
    std::mt19937 eng;
    eng.seed(std::time(nullptr));
    std::string res;
    unsigned val;

    while (stop) {
        val = eng() % tmp.size();
        res.insert(res.begin(), tmp[val]);
    }

    return res;
}
