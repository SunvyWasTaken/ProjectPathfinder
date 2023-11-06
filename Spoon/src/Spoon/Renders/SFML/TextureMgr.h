#pragma once
#include "Spoon/Core/Core.h"
#include <snpch.h>
#include <SFML/Graphics/Texture.hpp>

namespace sf {	class Texture; }

class TextureMgr
{
private:
	TextureMgr() : TextureRef(nullptr) {};
	virtual ~TextureMgr();

	TextureMgr(const TextureMgr&) = delete;

public:

	static TextureMgr& GetManager();

	sf::Texture* GetTexture() const { return TextureRef; };

	bool LoadTexture(const std::filesystem::path& path);

private:

	sf::Texture* TextureRef;

	static TextureMgr ManagerInstance;

};