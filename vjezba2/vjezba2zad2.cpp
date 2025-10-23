#include <iostream>
using namespace std;

struct Vector {
    int* elementi;
    int logicka_velicina;  
    int fizicka_velicina;  
};

// Kreira novi vektor
Vector* vector_new(int init) {
    Vector* v = new Vector;
    v->elementi = new int[init];
    v->logicka_velicina = 0;
    v->fizicka_velicina = init;
    return v;
}

void vector_delete(Vector* v) {
    delete[] v->elementi;
    delete v;
}

void vector_push_back(Vector* v, int vrijednost) {
    if (v->logicka_velicina == v->fizicka_velicina) {
        int nova_velicina = v->fizicka_velicina * 2;
        int* novi = new int[nova_velicina];
        for (int i = 0; i < v->logicka_velicina; i++)
            novi[i] = v->elementi[i];
        delete[] v->elementi;
        v->elementi = novi;
        v->fizicka_velicina = nova_velicina;
    }
    v->elementi[v->logicka_velicina++] = vrijednost;
}

void vector_pop_back(Vector* v) {
    if (v->logicka_velicina > 0)
        v->logicka_velicina--;
}

int vector_front(Vector* v) {
    if (v->logicka_velicina == 0) throw runtime_error("Vektor je prazan!");
    return v->elementi[0];
}

int vector_back(Vector* v) {
    if (v->logicka_velicina == 0) throw runtime_error("Vektor je prazan!");
    return v->elementi[v->logicka_velicina - 1];
}

int vector_size(Vector* v) {
    return v->logicka_velicina;
}

int main() {
    Vector* v = vector_new(2);

    vector_push_back(v, 5);
    vector_push_back(v, 10);
    vector_push_back(v, 15);

    cout << "Prvi: " << vector_front(v) << endl;
    cout << "Zadnji: " << vector_back(v) << endl;
    cout << "Velicina: " << vector_size(v) << endl;

    vector_pop_back(v);
    cout << "Nakon pop_back -> Velicina: " << vector_size(v) << endl;

    vector_delete(v);
    return 0;
}
