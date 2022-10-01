#include "field.hpp"

Field::Field(int fSize) :fSize(fSize) {
    field = new char*[fSize * 2 + 1];
    for (int i = 0; i < fSize * 2 + 1; ++i) {
        field[i] = new char[fSize * 2 + 1];
    }
    for (int i = 0; i < fSize * 2 + 1; ++i){
        for (int j = 0; j < fSize * 2 + 1; ++j){
            if (i % 2 == 0) {
                field[i][j] = '-';
            } else {
                if (j % 2 == 0) {
                    field[i][j] = '|';
                } else {
                    field[i][j] = ' ';
                }
            }
        }
    }
}
int Field::getFSize() const {
    return fSize;
}
char **Field::getField() const {
    return field;
}
Field::~Field() {
    for (int i = 0; i < fSize * 2 + 1; ++i) {
        delete[] field[i];
    }
    delete[] field;
}
