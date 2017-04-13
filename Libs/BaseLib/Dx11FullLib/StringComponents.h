/*!
@file StringComponents.h
@brief ������`��R���|�[�l���g
@copyright Copyright (c) 2017 WiZ Tamura Hiroki,Yamanoi Yasushi.
*/
#pragma once
#include "stdafx.h"

namespace basecross {

	//--------------------------------------------------------------------------------------
	///	StringSprite�R���|�[�l���g(������\��)
	//--------------------------------------------------------------------------------------
	class StringSprite : public Component{
	public:
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�R���X�g���N�^
		@param[in]	GameObjectPtr	�Q�[���I�u�W�F�N�g
		*/
		//--------------------------------------------------------------------------------------
		explicit StringSprite(const shared_ptr<GameObject>& GameObjectPtr);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�f�X�g���N�^
		*/
		//--------------------------------------------------------------------------------------
		virtual ~StringSprite();
		//--------------------------------------------------------------------------------------
		/*!
		@enum TextAlignment
		*/
		//--------------------------------------------------------------------------------------
		enum TextAlignment{
			//�����킹
			m_Left,
			//�������킹
			m_Center,
			//�E���킹
			m_Right
		};
		//�A�N�Z�T
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�t�H���g��ݒ肷��
		@param[in]	FontName �t�H���g��
		@param[in]	FontSize �t�H���g�T�C�Y
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetFont(const wstring& FontName, float FontSize);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�e�L�X�g�̃A���C�������g�𓾂�
		@return	�e�L�X�g�̃A���C�������g
		*/
		//--------------------------------------------------------------------------------------
		StringSprite::TextAlignment GetTextAlignment() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�e�L�X�g�̃A���C�������g��ݒ肷��
		@param[in]	Alignment �A���C�������g
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetTextAlignment(StringSprite::TextAlignment Alignment);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�e�L�X�g�𓾂�
		@return	�e�L�X�g
		*/
		//--------------------------------------------------------------------------------------
		const wstring& GetText() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�e�L�X�g��ݒ肷��
		@param[in]	str �e�L�X�g
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetText(const wstring& str);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�e�L�X�g��ǉ�����
		@param[in]	str �e�L�X�g
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void AddText(const wstring& str);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�t�H���g�F�𓾂�
		@return	�t�H���g�F
		*/
		//--------------------------------------------------------------------------------------
		const Color4& GetFontColor() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�t�H���g�F��ݒ肷��
		@param[in]	Col �t�H���g�F
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetFontColor(const Color4& Col);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�t�H���g���𓾂�
		@return	�t�H���g��
		*/
		//--------------------------------------------------------------------------------------
		const wstring& GetFontName() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�t�H���g�T�C�Y�𓾂�
		@return	�t�H���g�T�C�Y
		*/
		//--------------------------------------------------------------------------------------
		float GetFontSize() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�w�i�F�𓾂�
		@return	�w�i�F
		*/
		//--------------------------------------------------------------------------------------
		const Color4& GetBackColor() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�w�i�F��ݒ肷��
		@param[in]	Col �w�i�F
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetBackColor(const Color4& Col);
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�w�i�̃e�L�X�g�}�[�W���𓾂�
		@return	�w�i�̃e�L�X�g�}�[�W��
		*/
		//--------------------------------------------------------------------------------------
		Point2D<float> GetBackTextMargin() const;
		//--------------------------------------------------------------------------------------
		/*!
		@brief	�w�i�̃e�L�X�g�}�[�W����ݒ肷��
		@param[in]	p �w�i�̃e�L�X�g�}�[�W��
		@return	�Ȃ�
		*/
		//--------------------------------------------------------------------------------------
		void SetBackTextMargin(Point2D<float> p);

		float GetTextBlockWidth() const;
		void SetTextBlockWidth(float f);
		float GetTextBlockHeight() const;
		void SetTextBlockHeight(float f);

		ComPtr<IDWriteTextLayout>& GetTextLayout()const;
		ComPtr<IDWriteTextFormat>&	GetTextFormat()const;
		const DWRITE_TEXT_METRICS& GetDriteTextMetrics() const;

		const Point2D<float>& GetStartPosition() const;
		void SetStartPosition(const Point2D<float>& pos);

		Rect2D<float> GetTextRect() const;
		void SetTextRect(const Rect2D<float>& rect);

		//����
		virtual void OnUpdate()override;
		virtual void OnDraw()override;

	private:
		// pImpl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
	};


	//--------------------------------------------------------------------------------------
	//	class MultiStringSprite : public Component;
	//	�p�r: MultiStringSprite�R���|�[�l���g
	//	�����u���b�N�̕�����\���R���|�[�l���g
	//--------------------------------------------------------------------------------------
	class MultiStringSprite : public Component {
	public:
		explicit MultiStringSprite(const shared_ptr<GameObject>& GameObjectPtr);
		virtual ~MultiStringSprite();

		//�A�N�Z�T
		//�u���b�N����
		void SetFont(const wstring& FontName, float FontSize);
		const Color4& GetFontColor() const;
		void SetFontColor(const Color4& Col);
		const wstring& GetFontName() const;
		float GetFontSize() const;

		const Color4& GetBackColor() const;
		void SetBackColor(const Color4& Col);

		Point2D<float> GetBackTextMargin() const;
		void SetBackTextMargin(Point2D<float> p);
		ComPtr<IDWriteTextFormat>&	GetTextFormat()const;
		StringSprite::TextAlignment GetTextAlignment() const;
		void SetTextAlignment(StringSprite::TextAlignment Alignment);

		//�u���b�N�P��
		const wstring& GetText(size_t Index) const;
		void SetText(size_t Index, const wstring& str, bool Clip = false);
		void AddText(size_t Index, const wstring& str, bool Clip = false);
		void InsertTextBlock(const Rect2D<float>& Block, const wstring& str, bool Clip = false);
		void UpdateTextBlock(size_t Index, const Rect2D<float>& Block, const wstring& str, bool Clip = false);
		void ClearTextBlock();
		ComPtr<IDWriteTextLayout>& GetTextLayout(size_t Index)const;
		const DWRITE_TEXT_METRICS& GetDriteTextMetrics(size_t Index) const;


		//����
		virtual void OnUpdate()override;
		virtual void OnDraw()override;

	private:
		// pImpl�C�f�B�I��
		struct Impl;
		unique_ptr<Impl> pImpl;
	};




}

//end basecross
