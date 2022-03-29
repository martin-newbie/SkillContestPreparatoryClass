#include "DXUT.h"
#include "ImageManager.h"

void texture::CenterRender(Vector2 pos, float rot, Vector2 size, D3DCOLOR color)
{
	IMAGE->CenterRender(this, pos, rot, size, color);
}


void texture::Render(Vector2 pos, float rot, Vector2 size, D3DCOLOR color)
{
	IMAGE->Render(this, pos, rot, size, color);
}

void texture::Release()
{
	SAFE_RELEASE(texturePtr);
}


ImageManager::ImageManager()
	:m_sprite(nullptr)
{
	Init();
}


ImageManager::~ImageManager()
{
	Release();
}

texture* ImageManager::AddImage(const string& key, const string& path)
{
	auto find = m_images.find(key);
	if (find == m_images.end())
	{
		LPDIRECT3DTEXTURE9 texturePtr;
		D3DXIMAGE_INFO info;

		char ch[256];
		sprintf(ch, "./Resource/%s.png", path.c_str());

		if (D3DXCreateTextureFromFileExA(g_device, ch, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
			D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, nullptr, &texturePtr) == S_OK)
		{
			texture* text = new texture(texturePtr, info);
			m_images.insert(make_pair(key, text));
			return text;
		}

		return nullptr;
	}

	return find->second;
}

texture* ImageManager::FindImage(const string& key)
{
	auto find = m_images.find(key);
	if (find == m_images.end()) return nullptr;
	return find->second;
}




void ImageManager::Init()
{
	AddImage("Background", "mapBackGround");
	AddImage("Character", "Character");
	AddImage("Bullet", "Bullet");
	AddImage("Enemy", "Enemy");
	AddImage("Ammo", "Ammo");
	AddImage("Boss1", "Boss1");
	AddImage("Boss2", "Boss2");
	AddImage("Missiles", "Missiles");
	D3DXCreateSprite(g_device, &m_sprite);
}

void ImageManager::Release()
{
	for (auto iter : m_images)
	{
		iter.second->Release();
		SAFE_DELETE(iter.second);
	}
	m_images.clear();

	m_sprite->Release();
}

void ImageManager::Begin()
{
	m_sprite->Begin(D3DXSPRITE_ALPHABLEND);

}

void ImageManager::End()
{
	m_sprite->End();
}

void ImageManager::CenterRender(texture* texturePtr, Vector2 pos, float rot, Vector2 size, D3DCOLOR color)
{
	if (texturePtr)
	{
		D3DXMATRIXA16 mat;
		Vector2 CenterPos = Vector2(texturePtr->info.Width / 2, texturePtr->info.Height / 2);
		pos -= CenterPos;

		D3DXMatrixTransformation2D(&mat, &CenterPos, 0, &size, &CenterPos, rot, &pos);

		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, color);
	}
}



void ImageManager::Render(texture* texturePtr, Vector2 pos, float rot, Vector2 size, D3DCOLOR color)
{
	if (texturePtr)
	{
		D3DXMATRIXA16 mat;
		Vector2 CenterPos = Vector2(0, 0);
		pos -= CenterPos;

		D3DXMatrixTransformation2D(&mat, &CenterPos, 0, &size, &CenterPos, rot, &pos);

		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, color);
	}
}


void ImageManager::drawText(const string& str, Vector2 pos, float size, D3DCOLOR color, bool Center)
{
	D3DXMATRIX mat;
	if (!Center) {
		D3DXCreateFontA(g_device, size, 0, 10, 1, FALSE, HANGEUL_CHARSET, 0, 0, 0, "Fixedsys", &lpFont);
		D3DXMatrixTranslation(&mat, pos.x, pos.y, 0);
	}
	else {
		D3DXCreateFontA(g_device, size, 0, 0, 1, FALSE, HANGEUL_CHARSET, 0, 0, 0, "Fixedsys", &lpFont);
		D3DXMatrixTranslation(&mat, pos.x - size * (str.size() * 0.25), pos.y - size / 2.f, 0);
	}

	m_sprite->SetTransform(&mat);
	lpFont->DrawTextA(m_sprite, str.c_str(), str.size(), nullptr, DT_NOCLIP, color);

	SAFE_RELEASE(lpFont);
}

void ImageManager::LostDevice()
{
	m_sprite->OnLostDevice();
}

void ImageManager::ResetDevice()
{
	m_sprite->OnResetDevice();

}
