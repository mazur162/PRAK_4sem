#include <iostream>
#include <fstream>

class Person
{
    virtual void func() {}
public:
    std::string name() const;
};

class NamedPerson : public Person
{
public:
    NamedPerson();
    NamedPerson(const std::string &first_name, const std::string &last_name){};
    std::string get_first_name();
    std::string get_last_name();
private:
    std::string first_name;
    std::string last_name;
};

class MysteryPerson : public NamedPerson
{
public:
    MysteryPerson(const std::string &first_name, const std::string &last_name, std::istream &stream){};
    std::string get_first_name() const;
    std::string get_last_name() const;
    std::string spell() const;
private:
    std::string spell_str;
};

std::string MysteryPerson::spell() const
{
    return spell_str;
}

MysteryPerson::MysteryPerson (const std::string &first_name, const std::string &last_name)
{
    stream >> spell_str;
}

std::string NamedPerson::get_first_name () const
{
    return first_name;
}

std::string NamedPerson::get_last_name () const
{
    return last_name;
}

std::string BossPerson::name() const
{
    return "I am the BOSS";
}

std::ostream& operator<< (std::ostream &out, const Person &p) 
{
    out << p.func();
    return out;
}

friend std::ostream& operator<< (std::ostream &out, const Person &nm);

int main(int argc, const char **argv)
{
    Person *array[3];
    array[0] = new MysteryPerson("James", "Brown");
    array[1] = new BossPerson();
    array[2] = new MysteryPerson("Mystery", "M", std::cin);

    for (int i = 0; i < 3; i++)
    {
        std::cout << array[i]->name() << std::endl;
    }

    std::ofstream fout;
    if (argc < 2)
    {
        exit(0);
    }
    fout.open(argv[1], std::ios_base::trunc);
    if (fout.is_open() == 0)
    {
        exit(0);
    }
    for (int i = 0; i < 3; i++)
    {
        fout << array[i] << " ";
    }
    fout.close();
    for (int i = 0; i < 3; i++)
    {
        delete array[i];
    }
    return 0;
}