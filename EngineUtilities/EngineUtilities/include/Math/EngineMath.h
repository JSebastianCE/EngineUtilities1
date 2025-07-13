#pragma once

//#include "../Prerequisites.h" añadirlo a Prerequisites

/**
 * @file EngineMath.h
 * @brief Provides general mathematical utility functions used across the engine.
 */

namespace EU { //Acronimos como EU
  namespace Math {

    //Funciones Básicas

    /**
     * @brief Calcula la raíz cuadrada.
     */
    inline 
    float sqrt(float x) {
      if (x <= 0.f) return 0.f;
      float guess = x / 2.f;
      for (int i = 0; i < 10; ++i) {
        guess = 0.5f * (guess + x / guess);
      }
      return guess;
    }

    /**
     * @brief Devuelve el cuadrado de un número.
     */
    inline 
    float square(float x) {
      return x * x;
    }

    /**
     * @brief Devuelve el cubo de un número.
     */
    inline 
    float cube(float x) {
      return x * x * x;
    }

    /**
     * @brief Eleva x a la potencia n (entera).
     */
    inline 
    float power(float x, int n) {
      float result = 1.f;
      for (int i = 0; i < n; ++i) {
        result *= x;
      }
      return result;
    }

    /**
     * @brief Valor absoluto.
     */
    inline 
    float abs(float x) {
      return x < 0.f ? -x : x;
    }

    /**
     * @brief Devuelve el valor máximo entre dos números.
     */
    inline 
    float EMax(float a, float b) {
      return a > b ? a : b;
    }

    /**
     * @brief Devuelve el valor mínimo entre dos números.
     */
    inline 
    float EMin(float a, float b) {
      return a < b ? a : b;
    }

    //Redondeos

    /**
     * @brief Redondea al número entero más cercano.
     */
    inline 
    int round(float x) {
      return (x >= 0.f) ? static_cast<int>(x + 0.5f) : static_cast<int>(x - 0.5f);
    }

    /**
     * @brief Redondea hacia abajo.
     */
    inline 
    int floor(float x) {
      int i = static_cast<int>(x);
      return (x < 0.f && x != i) ? i - 1 : i;
    }

    /**
     * @brief Redondea hacia arriba.
     */
    inline 
    int ceil(float x) {
      int i = static_cast<int>(x);
      return (x > 0.f && x != i) ? i + 1 : i;
    }

    /**
     * @brief Valor absoluto flotante.
     */
    inline 
    float fabs(float x) {
      return abs(x);
    }

    // Funciones exponenciales y logarítmicas

    /**
     * @brief Módulo entre dos valores flotantes.
     */
    inline 
    float mod(float a, float b) {
      return a - b * floor(a / b);
    }

    /**
     * @brief Aproximación de e^x.
     */
    inline 
    float exp(float x) {
      float result = 1.0f;
      float term = 1.0f;
      for (int i = 1; i <= 10; ++i) {
        term *= x / static_cast<float>(i);
        result += term;
      }
      return result;
    }

    /**
     * @brief Logaritmo natural (ln) usando serie de Taylor para x cercano a 1.
     */
    inline 
    float log(float x) {
      if (x <= 0.f) return 0.f;
      float y = (x - 1) / (x + 1);
      float y2 = y * y;
      float result = 0.f;
      for (int i = 1; i < 10; i += 2) {
        result += 1.0f / static_cast<float>(i) * power(y, i);
      }
      return 2 * result;
    }

    /**
     * @brief Logaritmo base 10.
     */
    inline 
    float log10(float x) {
      return log(x) / 2.3025851f; // log10(e) ≈ 2.3025851
    }

    //Trigonometría

    inline 
    float sin(float x) {
      while (x > 3.14159265f) x -= 2.0f * 3.14159265f;
      while (x < -3.14159265f) x += 2.0f * 3.14159265f;
      float x2 = x * x;
      return x - (x2 * x) / 6.0f + (x2 * x2 * x) / 120.0f - 
        (x2 * x2 * x2 * x) / 5040.0f;
    }

    inline 
    float cos(float x) {
      while (x > 3.14159265f) x -= 2.0f * 3.14159265f;
      while (x < -3.14159265f) x += 2.0f * 3.14159265f;
      float x2 = x * x;
      return 1.0f - x2 / 2.0f + (x2 * x2) / 24.0f - (x2 * x2 * x2) / 720.0f;
    }

    inline 
    float tan(float x) {
      float c = cos(x);
      if (c == 0.f) return 0.f;
      return sin(x) / c;
    }

    inline 
    float asin(float x) {
      // Taylor series approximation for asin(x), valid for |x| <= 1
      float x2 = x * x;
      return x + (x2 * x) / 6.0f + (3 * x2 * x2 * x) / 40.0f;
    }

    inline 
    float acos(float x) {
      return 1.5707963f - asin(x); // pi/2 - asin(x)
    }

    inline 
    float atan(float x) {
      // Simplified series approximation
      return x - (x * x * x) / 3.0f + (x * x * x * x * x) / 5.0f;
    }

    inline 
    float sinh(float x) {
      return (exp(x) - exp(-x)) / 2.0f;
    }

    inline 
    float cosh(float x) {
      return (exp(x) + exp(-x)) / 2.0f;
    }

    inline 
    float tanh(float x) {
      return sinh(x) / cosh(x);
    }

    //Conversión Angular 

    /**
     * @brief Convierte grados a radianes.
     */
    inline 
    float radians(float degrees) {
      return degrees * 3.14159265f / 180.0f;
    }

    /**
     * @brief Convierte radianes a grados.
     */
    inline 
    float degrees(float radians) {
      return radians * 180.0f / 3.14159265f;
    }

  } // namespace Math
} // namespace EngineUtilities
