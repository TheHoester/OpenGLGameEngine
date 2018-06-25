#pragma once

#include "Model.h"

namespace GameEngine
{
	namespace Rendering
	{
		namespace Models
		{
			class Quad : public Model
			{
			public:
				Quad(void);
				~Quad(void);

				void Create(void);
				virtual void Draw(void) override final;
				virtual void Update(void) override final;
			};
		}
	}
}