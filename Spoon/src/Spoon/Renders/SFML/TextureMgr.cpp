#include "TextureMgr.h"
//#include <SFML/Graphics/Texture.hpp>


//TextureMgr::~TextureMgr()
//{
//	delete TextureRef;
//}
//
//TextureMgr& TextureMgr::GetManager()
//{
//	return ManagerInstance;
//}
//
//bool TextureMgr::LoadTexture(const std::filesystem::path& path)
//{
//	if (!TextureRef)
//	{
//		TextureRef = new sf::Texture();	
//	}
//	// Check si le file exist
//	if (!std::filesystem::exists(path.native()))
//	{
//		std::cerr << "Texture file doesn't exist : " << path << std::endl;
//		return false;
//	}
//
//	return TextureRef->loadFromFile(path.generic_string());
//}
