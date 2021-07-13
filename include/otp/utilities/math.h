#ifndef _INCLUDE_OTP_UTILITIES_MATH_H
#define _INCLUDE_OTP_UTILITIES_MATH_H

namespace utility {
namespace math {

class Vec2 {
public:
	int x, y;

	Vec2();
	Vec2(int x, int y);
	
	void operator+=(const Vec2 &b);
	void operator-=(const Vec2 &b);
	void operator*=(int k);
	void operator/=(int k);

	static Vec2 zero();

	Vec2 operator+(const Vec2 &b) const;
	Vec2 operator-(const Vec2 &b) const;
	Vec2 operator*(int k) const;
	Vec2 operator/(int k) const;
	Vec2 operator-() const;
};

} // namespace math
} // namespace utility

#endif // _INCLUDE_OTP_UTILITIES_MATH_H

