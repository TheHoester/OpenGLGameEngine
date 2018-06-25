#pragma once

#include "Model.h"

namespace GameEngine
{
	namespace Rendering
	{
		namespace Models
		{
			class Triangle : public Model
			{
			public:
				Triangle(void);
				~Triangle(void);

				void Create(void);
				virtual void Update(void) override final;
				virtual void Draw(void) override final;
			};
		}
	}
}