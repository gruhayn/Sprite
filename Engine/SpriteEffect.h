#pragma once

#include "Colors.h"
#include "Graphics.h" 

namespace SpriteEffect {
	
	class NonChroma {
	public:
		void operator()(Color cSrc, int xDest, int yDest, Graphics& gfx) {
			gfx.PutPixel(xDest, yDest, cSrc);	
		}

	};

	class Chroma {
	public:
		Chroma(Color chroma) : chroma(chroma){}
		void operator()(Color cSrc, int xDest, int yDest, Graphics& gfx) {
			
			if (cSrc != chroma)
			{
				gfx.PutPixel(xDest, yDest, cSrc);
			}
		}
	private:
		Color chroma;

	};

	class Substitute {
	public:
		Substitute(Color chroma, Color substitute) :chroma(chroma), substitute(substitute) {}

		void operator()(Color cSrc, int xDest, int yDest, Graphics& gfx) {
			
			if (cSrc != chroma)
			{
				// use substitute color instead of color from the surface (if not chroma)
				gfx.PutPixel(xDest, yDest, substitute);
			}
		}
	private:
		Color chroma;
		Color substitute;

	};

	class Ghost {
	public:
		Ghost(Color chroma): chroma(chroma) {}

		void operator()(Color cSrc, int xDest, int yDest, Graphics& gfx) {
			
			if (cSrc != chroma)
			{
				const Color dstPixel = gfx.GetPixel(xDest, yDest);

				const Color blendedPixel = {
					unsigned char((dstPixel.GetR() + cSrc.GetR()) / 2),
					unsigned char((dstPixel.GetG() + cSrc.GetG()) / 2),
					unsigned char((dstPixel.GetB() + cSrc.GetB()) / 2)
				};
				gfx.PutPixel(xDest, yDest, blendedPixel);
			}
		}
	private:
		Color chroma;
	};

}
