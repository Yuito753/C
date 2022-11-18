
#pragma once

#include "Map.h"
/// <summary>
/// ダイクストラ　経路探索クラス
/// </summary>
class Dijkstra {
public:
	struct CELL {
		int x;	//列
		int y;	//行
	};
private:
	unsigned char m_score[MAP_HEIGHT][MAP_WIDTH];			//MAP全体のマスごとの距離配列
	int m_path_size;										//ゴールまでの距離
	CELL m_goal;											//ゴール地点
	static const unsigned int m_max_value = 255;						//最大距離
	CELL m_path[m_max_value];									//経路
	bool _FindShortestPath(Map* map, int x, int y, unsigned char score);

public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Dijkstra();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Dijkstra();

	/// <summary>
	/// 経路探索　目的地から出発地点までのノードの情報を返す
	/// </summary>
	/// <param name="map">経路対象のマップ</param>
	/// <param name="start">出発地点</param>
	/// <param name="goal">目的地点</param>
	/// <returns>true:経路発見</returns>
	bool FindShortestPath(Map* map, const CVector2D& start, const CVector2D& goal);

	/// <summary>
	/// パスの数、目的地までの距離を取得
	/// </summary>
	/// <returns>パスの数、目的地までの距離</returns>
	int GetPathSize() {
		return m_path_size;
	}
	/// <summary>
	/// 経路上の指定番号の座標を取得
	/// </summary>
	/// <param name="idx">添字</param>
	/// <returns>座標</returns>
	CVector2D GetPathPoint(unsigned char idx) {
		return CVector2D(m_path[idx].x * MAP_TIP_SIZE + MAP_TIP_SIZE / 2,
			m_path[idx].y * MAP_TIP_SIZE + MAP_TIP_SIZE / 2);
	}
	/// <summary>
	/// デバッグ描画
	/// </summary>
	void Draw();

};