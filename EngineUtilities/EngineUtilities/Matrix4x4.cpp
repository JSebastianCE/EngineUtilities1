#include <Matrices/Matrix4x4.h>

namespace EU {

  Matrix4x4::Matrix4x4() {
    setIdentity();
  }

  void 
  Matrix4x4::setIdentity() {
    for (int i = 0; i < 4; ++i)
      for (int j = 0; j < 4; ++j)
        m[i][j] = (i == j) ? 1.f : 0.f;
  }

  void 
  Matrix4x4::setScale(float scaleX, float scaleY, float scaleZ) {
    setIdentity();
    m[0][0] = scaleX;
    m[1][1] = scaleY;
    m[2][2] = scaleZ;
  }

  CVector3
  Matrix4x4::transformPoint(const CVector3& vec) const {
    float x = m[0][0] * vec.x + m[0][1] * vec.y + m[0][2] * vec.z + m[0][3];
    float y = m[1][0] * vec.x + m[1][1] * vec.y + m[1][2] * vec.z + m[1][3];
    float z = m[2][0] * vec.x + m[2][1] * vec.y + m[2][2] * vec.z + m[2][3];
    float w = m[3][0] * vec.x + m[3][1] * vec.y + m[3][2] * vec.z + m[3][3];

    if (w != 0.f) {
      x /= w;
      y /= w;
      z /= w;
    }

    return CVector3(x, y, z);
  }

  // Aquí defines también otros métodos que declaraste

} // namespace EU
