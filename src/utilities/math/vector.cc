#include <otp/utility.h>
using namespace utility::math;

Vec2::Vec2(): x(0), y(0) {}
Vec2::Vec2(int x, int y): x(x), y(y) {}

void Vec2::operator+=(const Vec2 &b) {
	this->x += b.x;
	this->y += b.y;
}

void Vec2::operator-=(const Vec2 &b) {
	this->x -= b.x;
	this->y -= b.y;
}

void Vec2::operator*=(int k) {
	this->x *= k;
	this->y *= k;
}

void Vec2::operator/=(int k) {
	this->x /= k;
	this->y /= k;
}

Vec2 Vec2::zero() {
	return {0, 0};
}

Vec2 Vec2::operator+(const Vec2 &b) const {
	return {this->x + b.x, this->y + b.y};
}

Vec2 Vec2::operator-(const Vec2 &b) const {
	return {this->x - b.x, this->y - b.y};
}

Vec2 Vec2::operator*(int k) const {
	return {this->x * k, this->y * k};
}

Vec2 Vec2::operator/(int k) const {
	return {this->x / k, this->y / k};
}

Vec2 Vec2::operator-() const {
	return {-this->x, -this->y};
}

