#include "Field.h"

Field::Field() :Base(eType_Field)
{
	m_haikei = COPY_RESOURCE("haikei", CImage);
	
}
void Field::Draw()
{
	float sc;
	m_haikei.Draw();
	sc = m_scroll.x / 4;
	

}

