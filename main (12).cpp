#include <iostream>
#include<string>
#include <cctype>
using namespace std;

int main() {
    setlocale(LC_ALL, "Ru");
    int count, number, numberTwo, Switch = 3;
    string stroka, result, number1, numberTwo1, Switch1;
    number = 0;
    numberTwo = 0;
    cout << "Введите фразу (строку): ";
    getline(cin, stroka);

    cout << "Найти цифру по номеру или диапазону?" << "\n";
    cout << "Чтобы найти цифру по номеру ввдеите - 1, по диапазону - 2:";

    try {
        cin >> Switch1;
        Switch = stod(Switch1);
    } catch (const invalid_argument&) {
        cout << "Вы можете ответить только 1 или 2"; 
        return -1;
    }
    
    if (Switch == 1) {
        try {
            cout << "Введите номер цифры: "; // Проверка на ввод символов, а не цифры
            cin >> number1;
            number = stod(number1);
        } catch (const invalid_argument&) {
            cout << "Номер цифры может быть только числом, введите данные заново"; 
            return -1;
        }
        for (int i = 0; i < stroka.length(); i++) {
            if (isdigit(stroka[i])){
                count += 1;
            }
            if (number == count){
                result = stroka[i];
                break;
            }
        }
    
        if (count < number) {
            cout << "Цифры под номером " << number << " не существует"; // проверка на существование номера
            return -1;
        }
    
        if (count == 0) {
            cout << "В вышей фразе (строке) нет ни одной цифры"; // проверка на наличие цифры в строке
            return -1;
        }
        
        cout << "Цифрой номер " << number << " является " << result << endl;
    }

    if (Switch == 2) {
        try {
            cout << "Введите диапазон (две цифры, например 1 3): "; // Проверка на ввод символов, а не цифры
            cin >> number1 >> numberTwo1;
            number = stod(number1);
            numberTwo = stod(numberTwo1);
        } catch (const invalid_argument&) {
            cout << "Диапазон может быть только числами, введите данные заново"; 
            return -1;
        }

        if (numberTwo != 0) {
            cout << "Цифрами в диапазоне от " << number << " до " << numberTwo << " являются: ";
            for (int i = 0; i < stroka.length(); i++) {
                if (isdigit(stroka[i]))
                    count += 1;
                if (number <= count && count <= numberTwo && isdigit(stroka[i]))
                    cout << stroka[i] << " ";
            }
        }
    }

    return 0;
}
            return -1;
        }
    
        if (count == 0){
            cout << "В вышей фразе (строке) нет ни одной цифры"; // проверка на наличие цифры в строке
            return -1;
        }
        
        cout << "Цифрой номер " << number << " является " << result << endl;
    }
    
    
    
    if (Switch == 2){
        
        try{
        cout << "Введите диапазон (две цифры, например 1 3): "; // Проверка на ввод символов, а не цифры
        cin >> number1 >> numberTwo1;
        number = stod(number1);
        numberTwo = stod(numberTwo1);
        }
        catch(const invalid_argument&){
            cout << "Диапазон может быть только числами, введите данные заного"; 
            return -1;
        }
        
        if (numberTwo !=0){
            cout << "Цифрами в диапазоне от " << number << " до " << numberTwo << " являются: ";
            for (int i; i < stroka.length(); i++){
            if (isdigit(stroka[i])){
                count += 1;
            }
            if (number <= count && count <= numberTwo){
                result = stroka[i];
                cout << result << " ";
            }
        }
        
        }
    
    }
    
    
    

    return 0;
}




