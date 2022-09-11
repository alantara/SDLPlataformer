#include "TileLayer.h"
#include "../graphics/TextureManager.h"

TileLayer::TileLayer(int tilesize, int rowcount, int colcount, TileMap tilemap, TilesetList tilesets)
:m_TileSize(tilesize), m_RowCount(rowcount), m_ColCount(colcount), m_Tilemap(tilemap), m_Tilesets(tilesets)
{
    for(unsigned int i = 0; i < m_Tilesets.size(); i++)
    {
        TextureManager::GetInstance()->Load(m_Tilesets[i].Name, "assets/maps/" + m_Tilesets[i].source);
    }
}

void TileLayer::Render()
{
    for(unsigned int i = 0; i < m_RowCount; i++)
    {
        for(unsigned int j = 0; j < m_ColCount; j++)
        {
            int tileID = m_Tilemap[i][j];

            if(tileID == 0) continue;

            int index = 0;
            if(m_Tilesets.size() > 1)
            {
                for(unsigned int k = 1; k < m_Tilesets.size(); k++)
                {
                    if(tileID > m_Tilesets[k].firstID && tileID < m_Tilesets[k].lastID)
                    {
                        tileID = tileID + m_Tilesets[k].tileCount - m_Tilesets[k].lastID;
                        index = k;
                        break;
                    }
                }
            }

            Tileset ts = m_Tilesets[index];
            int tileRow = tileID/ts.colCount;
            int tileCol = tileID - tileRow * ts.colCount - 1;

            if(tileID % ts.colCount == 0)
            {
                tileRow--;
                tileCol = ts.colCount - 1;
            }

            TextureManager::GetInstance()->DrawTile(ts.Name, ts.tileSize, j*ts.tileSize, i*ts.tileSize, tileRow, tileCol);            
        }
    }
}

void TileLayer::Update()
{

}