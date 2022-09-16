#include "Field.h"

Field::Field() :Base(eType_Field)
{
	m_background = COPY_RESOURCE("Backgound", CImage);
	m_ground_y = 1080;
}
void Field::Draw()
{
	
	m_background.SetRect(0,0,1920,1080);
	m_background.Draw();

	

}

