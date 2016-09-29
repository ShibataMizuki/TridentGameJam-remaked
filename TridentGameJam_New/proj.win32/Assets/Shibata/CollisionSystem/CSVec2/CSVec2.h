#pragma once

#include<string>

constexpr float EPS = (float)1e-9;

struct CSVec2
{
	//! X�v�f,Y�v�f
	float x, y;

	/*==============================
	�R���X�g���N�^
	===============================*/
	CSVec2();
	CSVec2(float x, float y);

	/*==============================
	�I�y���[�^�̃I�[�o�[���[�h
	===============================*/
	CSVec2 operator+(const CSVec2& rv)const;
	CSVec2 operator-(const CSVec2& rv)const;
	CSVec2 operator*(float rv)const;
	CSVec2 operator/(float rv)const;

	/*==============================
	���̑��֐�
	===============================*/
	//! �x�N�g���̒������Z�o
	float getLength()const;
	//! �x�N�g���𐳋K��
	void normalize();
	//! ���K�������x�N�g�����擾
	CSVec2 getNormalized()const;
	//! �x�N�g���̓���
	float dot(const CSVec2& rv)const;
	//! �x�N�g���̊O��
	float cross(const CSVec2& rv)const;

	////////////////////////////////////////
	//! �x�N�g���̓���
	static constexpr float calcDot(const CSVec2& lv, const CSVec2& rv);
	//! �x�N�g���̊O��
	static constexpr float calcCross(const CSVec2& lv, const CSVec2& rv);
	//! �x�N�g���̒��𔻒�
	static constexpr bool isOrthogonal(const CSVec2& lv, const CSVec2& rv);
	//! �x�N�g���̕��s����
	static constexpr bool isParallel(const CSVec2& lv, const CSVec2& rv);

	//! @brief �_���v��������擾
	std::string dump()const;
};