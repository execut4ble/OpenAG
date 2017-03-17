//+msk
#ifndef HUD_SCORES_HPP
#define HUD_SCORES_HPP
#include <vector> // msk needs std::vector
#include <string> // msk needs std::string and string streams
#include <sstream>
#include <algorithm> // msk needs std::sort and std::reverse

namespace ScoreTabs
{
	struct tab_t
	{
		int score;
		int teamnum;
		std::string name;
		inline bool operator<(const tab_t& b)
		{
			return score < b.score;
		}
	};

	class ScoreList final
		: public CHudBase
	{
		std::vector<tab_t> tabs;

		cvar_t * cl_scores;
		cvar_t * cl_scores_x;
		cvar_t * cl_scores_y;
		cvar_t * cl_scores_width;
		cvar_t * cl_scores_brightness;

		cvar_t * cl_scores_hpad;
		cvar_t * cl_scores_vpad;

	public:
		int Init() override;
		int VidInit() override;
		int Draw(float flTime) override;

		inline void ClearTabs(void)
		{
			tabs.clear();
		}
		inline void AppendTab(const tab_t &t)
		{
			tabs.push_back(t);
		}
		void DrawSortedTabs();
	};
}

#endif /* CL_SCORES_HPP */
//msk-#pragma once
