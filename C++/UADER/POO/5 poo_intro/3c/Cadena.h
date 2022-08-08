#ifndef CADENA_H
#define CADENA_H


class Cadena{
private:
    char *str;
    int size = 0;
public:
    Cadena(char *str);
    int find(char);
    void add_final(char);
    void add_start(char);
    void remove(char);
    void uppercase();
    char *getStr() const;
    int getSize() const;
};

#endif // CADENA_H
