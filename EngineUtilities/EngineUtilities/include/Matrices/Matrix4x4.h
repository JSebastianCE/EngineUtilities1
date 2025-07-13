#pragma once

#include "../Prerequisites.h"
#include <Vectors/Vector3.h>
#include <Vectors/Vector4.h>
#include <Math/EngineMath.h>

/**
 * @file Matrix4x4.h
 * @brief Represents a 4x4 matrix with standard operations for 3D transformations.
 */

namespace EU {

  /**
   * @class Matrix4x4
   * @brief Defines a 4x4 matrix used for 3D transformations including translation, scaling, and rotation.
   */
  class
  Matrix4x4 {
  public:

    float m[4][4];

    /**
     * @brief Default constructor. Initializes as identity matrix.
     */
    Matrix4x4();

    /**
     * @brief Parameterized constructor.
     * @param values 16 float values in row-major order.
     */
    Matrix4x4(
      float m00, float m01, float m02, float m03,
      float m10, float m11, float m12, float m13,
      float m20, float m21, float m22, float m23,
      float m30, float m31, float m32, float m33);

    /**
     * @brief Adds two matrices.
     * @param other Matrix to add.
     * @return Resulting matrix.
     */
    Matrix4x4
    operator+(const Matrix4x4& other) const;

    /**
     * @brief Subtracts two matrices.
     * @param other Matrix to subtract.
     * @return Resulting matrix.
     */
    Matrix4x4
    operator-(const Matrix4x4& other) const;

    /**
     * @brief Multiplies the matrix by a scalar.
     * @param scalar Scalar value.
     * @return Scaled matrix.
     */
    Matrix4x4
    operator*(float scalar) const;

    /**
     * @brief Multiplies this matrix by another 4x4 matrix.
     * @param other Right-hand side matrix.
     * @return Resulting matrix.
     */
    Matrix4x4
    operator*(const Matrix4x4& other) const;

    /**
     * @brief Multiplies the matrix by a 4D vector.
     * @param vec 4D vector.
     * @return Transformed vector.
     */
    CVector4
    operator*(const CVector4& vec) const;

    /**
     * @brief Multiplies the matrix by a 3D vector using homogeneous coordinates.
     * @param vec 3D vector.
     * @return Transformed 3D vector.
     */
    CVector3
    transformPoint(const CVector3& vec) const;

    /**
     * @brief Adds another matrix to this matrix.
     * @param other Matrix to add.
     * @return Reference to this matrix.
     */
    Matrix4x4&
    operator+=(const Matrix4x4& other);

    /**
     * @brief Subtracts another matrix from this matrix.
     * @param other Matrix to subtract.
     * @return Reference to this matrix.
     */
    Matrix4x4&
    operator-=(const Matrix4x4& other);

    /**
     * @brief Multiplies this matrix by a scalar.
     * @param scalar Scalar value.
     * @return Reference to this matrix.
     */
    Matrix4x4&
    operator*=(float scalar);

    /**
     * @brief Accesses an element in the matrix.
     * @param row Row index (0-3).
     * @param col Column index (0-3).
     * @return Reference to the element.
     */
    float&
    operator()(int row, int col);

    /**
     * @brief Const access to a matrix element.
     * @param row Row index (0-3).
     * @param col Column index (0-3).
     * @return Const reference to the element.
     */
    const
    float& operator()(int row, int col) const;

    /**
     * @brief Returns the transpose of this matrix.
     * @return Transposed matrix.
     */
    Matrix4x4
    transpose() const;

    /**
     * @brief Sets this matrix as the identity matrix.
     */
    void
    setIdentity();

    /**
     * @brief Sets a scale matrix.
     * @param scaleX Scale on X-axis.
     * @param scaleY Scale on Y-axis.
     * @param scaleZ Scale on Z-axis.
     */
    void
    setScale(float scaleX, float scaleY, float scaleZ);

    /**
     * @brief Sets a translation matrix.
     * @param tx Translation on X.
     * @param ty Translation on Y.
     * @param tz Translation on Z.
     */
    void
    setTranslation(float tx, float ty, float tz);

    /**
     * @brief Sets a rotation matrix around the Z-axis (in 2D space).
     * @param radians Angle in radians.
     */
    void
    setRotation(float radians);

    /**
     * @brief Returns an identity matrix.
     * @return Identity matrix.
     */
    static
    Matrix4x4 identity();

    /**
     * @brief Returns a zero matrix.
     * @return Zero-filled matrix.
     */
    static
    Matrix4x4 zero();
  };

} // namespace EU
