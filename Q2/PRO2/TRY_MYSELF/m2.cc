#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

double absolute (double a) {
  if (a >= 0) return a;
  return -a;
}
void inverse_vector (vector<double>& p) {
  for (int i = 0;i < p.size()/2; ++i) {
    double aux = p[i];
    p[i] = p[p.size()-1-i];
    p[p.size()-1-i] = aux;
  }
}

double evaluate (const vector<double>& p, double x) {
  double suma;
  int n = p.size();

  if (n > 1) suma = p[n-2] +p[n-1]*x;
  else suma = p[0];

  for (int i = n-3; i >= 0; --i) suma = p[i] + x*suma;
  return suma;  
}

vector<double> derivada_polinomio (const vector<double>p) {
  vector<double> d(p.size()-1);
  for (int i = d.size() - 1; i >= 0; --i) {
    d[i] = p[i + 1] * (i + 1);
  }
  return d;
} 


void biseccion (const vector<double>& p, double x1, double x2, int& n, double& answer, double precision) {
  if (x1 > x2) {
    double aux = x1;
    x1 = x2;
    x2 = aux;
  }

  if (evaluate (p,x1) > 0 != evaluate (p,x2) > 0) {
    n = log(1/precision)/log(2); //n és la part entera superior de log(1/precision)/log(2) - 1. Com n és int, agafa la part inferior, que es igual a la superior si li restem 1.
    
    for (int i = 0; i < n; ++i) {
      double half_point = x1 + (absolute(x1-x2))/2;
      bool sign_a = evaluate (p,x1) > 0;
      bool sign_b = evaluate (p,x2) > 0;
      bool sign_half = evaluate (p, half_point) > 0;
      
      if (sign_a != sign_half) x2 = half_point;
      else x1 = half_point; 
    }
    answer = x1 + (absolute(x1-x2))/2;
  }
  else cout << "ERROR: El signe de f(a) == signe de f(b). Per tant, el Teorema de Bolzano no garanteix una solució y el métode de la bisecció no funcionarà de la manera esperada" << endl;
}


void secante (const vector<double>& p, double x1, double x2, int& n, double& answer, double precision) {
  n = 0;
  cout << "Sin iterar: x = " << x2 << " Error avaluació:" << absolute(evaluate(p,x2)) << " Diferencia respostes:" << absolute(x1 - x2) << endl;
  while (absolute(evaluate(p,x2)) > precision or absolute(x1 - x2) > precision) {
    
    double f_a = evaluate(p,x1);
    double f_b = evaluate(p,x2);
    double aux_x1 = x1;
    x1 = x2;
    x2 = x2-f_b*((x2 - aux_x1)/(f_b - f_a));
    ++n;
    cout << "Iteració " << n << ": x = " << x2 << " Error avaluació:" << absolute(evaluate(p,x2)) << " Diferencia respostes:" << absolute(x1 - x2) << endl;
  }
  answer = x2;
}

//Pre: Entra una función polinómica representado en un vector de doubles (s
void tangente (const vector<double>& p, double x1, int& n, double& answer, double precision) {
  n = 0;
  double x2 = x1;
  vector<double> derivada = derivada_polinomio(p);
  cout << "Sin iterar: x = " << x2 << " Error avaluació:" << absolute(evaluate(p,x2)) << " Diferencia respostes:" << absolute(x1 - x2) << endl;
  while (absolute(evaluate(p,x2)) > precision or absolute(x1 - x2) > precision) {
    x1 = x2;
    x2 = x2 - (evaluate(p,x2)/evaluate(derivada,x2));
    ++n;
    cout << "Iteració " << n << ": x = " << x2 << " Error avaluació:" << absolute(evaluate(p,x2)) << " Diferencia respostes:" << absolute(x1 - x2) << endl;
  }
  
  answer = x2;
}


int main() {
  cout.setf(ios::fixed);
  cout.precision(16);
  
  int n;
  cout << "Indica el grado del polinomio" << endl;
  while (cin >> n) {
    cout << "Introduce el polinomio: (sin x, si hay algún coeficiente que sea 0, indicalo)" << endl;
    /*string polinomio_entrada;
    cin >> polinomio_entrada;*/
    
    vector<double> p(n + 1);
    for (int i = 0; i < n + 1; ++i) cin >> p[i];
    inverse_vector(p);
    
    cout << endl << "Escoge el método que quieres usar para encontrar una solución:" << endl;
    cout << endl << "Bisección: 1" << endl << "Secante: 2" << endl << "Tangente/Newton-Raphson: 3" << endl << "Evaluar x: 4" << endl;
  
    
    string choice;
    cin >> choice;
    
    if (choice == "1" or choice == "bisección" or choice == "Bisección") {
      cout << "Escoge los valors del intervalo donde se encuentra la solución" << endl;
      double a, b, answer, precision;
      int n;
      cin >> a >> b;
      cout << "Escoge la precisión de la solución" << endl;
      cin >> precision;
  
      biseccion(p, a, b, n, answer, precision);
      cout << "x = " << answer << " Número mínimo de iteraciones: " << n << endl; 
    }
    else if (choice == "2" or choice == "secante" or choice == "Secante") {
      cout << "Escoge los puntos iniciales" << endl;
      double a, b, answer, precision;
      int n;
      cin >> a >> b;
      cout << "Escoge la precisión de la solución" << endl;
      cin >> precision;
  
      secante(p, a, b, n, answer, precision);
      cout << "x = " << answer << " Número mínimo de iteraciones: " << n << endl; 
    }
  
    else if (choice == "3" or choice == "tangente" or choice == "Tangente" or choice == "Newton-Raphson") {
      cout << "Escoge el punto inicial" << endl;
      double a, answer, precision;
      int n;
      cin >> a;
      cout << "Escoge la precisión de la solución" << endl;
      cin >> precision;
  
      tangente(p, a, n, answer, precision);
      cout << "x = " << answer << " Número mínimo de iteraciones: " << n << endl;  
    }
    else if (choice == "4") {
      cout << "Introduce el valor de x a sustituir: " << endl;
      double x;
      cin >> x;
      cout << evaluate(p,x) << endl;
    }
    cout << endl << "Indica el grado del nuevo polinomio" << endl;
  }
}