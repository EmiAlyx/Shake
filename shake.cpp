#include"shake.h"
snake::snake() {
	this->length = 2;
	this->b1[0].x = WID / 2;
	this->b1[0].y = HIG / 2;
	this->b1[1].x = WID / 2 - 1;
	this->b1[1].y = HIG / 2;
}
void snake::reset() {
	this->length = 2;
	this->b1[0].x = WID / 2;
	this->b1[0].y = HIG / 2;
	this->b1[1].x = WID / 2 - 1;
	this->b1[1].y = HIG / 2;
}
void snake::get_long() {
	this->length++;
}
bool snake::ifclash() {
	if (this->b1[0].x<0 || this->b1[0].x > WID || this->b1[0].y < 0 || this->b1[0].y>HIG) {
		cout << "你碰到了墙壁" << endl;
		return true;
	}
	for (int i = 1; i < this->length; i++) {
		if (this->b1[0].x == this->b1[i].x && this->b1[0].y == this->b1[i].y) {
			cout << "你咬到了自己" << endl;
			return true;
		}
	}
	return 0;
}
food::food() {
	this->x = (rand() % WID) - 1;
	this->y = (rand() % HIG) - 1;
}
food::food(body a[],int length) {
	while (1) {
		this->x = (rand() % WID) - 1;
		this->y = (rand() % HIG) - 1;
		for (int i = 0; i < length; i++) {
			if (this->x == a[i].x && this->y == a[i].y) {
				break;
			}
			if (i == length - 1) {
				return;
			}
		}
	}
}
void food::reset(body a[], int length) {
	while (1) {
		this->x = (rand() % WID) - 1;
		this->y = (rand() % HIG) - 1;
		for (int i = 0; i < length; i++) {
			if (this->x == a[i].x && this->y == a[i].y) {
				break;
			}
			if (i == length - 1) {
				return;
			}
		}
	}
}