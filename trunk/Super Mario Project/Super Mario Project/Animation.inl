////////////////////////////////////////////////////////////////////////
// Animation.cpp
// Super Mario Project
// Copyright (C) 2011  
// Lionel Joseph lionel.r.joseph@gmail.com
// Olivier Guittonneau openmengine@gmail.com
////////////////////////////////////////////////////////////////////////

template<typename T>
Animation<T>::Animation(map<T, int>& nbSpritesByState, map<T, int>& vAnimByState) :
_nbSpritesByState(nbSpritesByState), 
	_vAnimByState(vAnimByState)
{

}

template<typename T>
void Animation<T>::setMapNbSprites(map<T, int>& nbSpritesByState)
{
	_nbSpritesByState = nbSpritesByState;
}

template<typename T>
void Animation<T>::setMapVAnim(map<T, int>& vAnimByState)
{
	_vAnimByState = vAnimByState;
}

template<typename T>
void Animation<T>::setCurrentState(T state)
{
	_currentState = state;
}

template<typename T>
int Animation<T>::getNbSpritesMax()
{
	map<T, int>::iterator itNbSprites;
	int nbSpritesMax = 0;

	for(itNbSprites = _nbSpritesByState.begin(); itNbSprites !=  _nbSpritesByState.end(); ++itNbSprites)
	{
		if(itNbSprites->second > nbSpritesMax)
			nbSpritesMax = itNbSprites->second;
	}

	return nbSpritesMax;
}

template<typename T>
void Animation<T>::render(Texture* texture, RenderWindow& app, Vector2f& position)
{
	int numState = static_cast<int>(_currentState);
	Vector2f spriteSize = Vector2f(
		texture->getImage()->GetWidth() / getNbSpritesMax(),
		texture->getImage()->GetHeight() / _nbSpritesByState.size());
	Sprite sprite = texture->getSprite();
	
	sprite.SetSubRect(
		IntRect(
		0, 
		numState * spriteSize.y,
		spriteSize.x,
		(numState + 1) * spriteSize.y));

	sprite.SetPosition(position);
	

	app.Draw(sprite);
}