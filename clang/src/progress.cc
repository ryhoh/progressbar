// Copyright (c) 2016-2019 Tetsuya Hori
// Released under the MIT license
// https://opensource.org/licenses/mit-license.php

// 修正 - 2019/03/17 堀哲也
// 堀哲也 2016/11/05

#include <iostream>

#include "progress.h"

Progress::Progress(int max)
{
    if (max < 1)
    {
        std::cerr << "ProgressBar error #1: bad max error" << std::endl;
        exit(EXIT_FAILURE);
    }

    this->max = max;
    this->pos = 0;
}

Progress::~Progress()
{
}

std::string Progress::generateString()
{
	const int bar_num = this->pos * BAR_LENGTH / this->max;
    std::string percent = std::to_string(this->pos * 100 / this->max);
    {
        // パーセントを3桁にする
        const int percent_len = percent.length();
        for (int i=0; i < 3 - percent_len; ++i)
            percent = " " + percent;
    }

	std::string res = "|";
	for(int i = 0; i < bar_num; ++i) res += DONE_CHAR;
	for(int i = bar_num; i < BAR_LENGTH; ++i) res += YET_CHAR;
	res += "| " + percent + "%    NUM:[ " +\
        std::to_string(pos) + " / " + std::to_string(max) + " ]";

	return res;
}

void Progress::click()
{
    if (this->pos < this->max)
        this->pos++;
}


SimpleProgress::~SimpleProgress()
{
}

std::string SimpleProgress::generateString()
{
    const int bar_num = this->getPos() * BAR_LENGTH / this->getMax();
    std::string percent = std::to_string(this->getPos() * 100 / this->getMax());
    {
        // パーセントを3桁にする
        const int percent_len = percent.length();
        for (int i=0; i < 3 - percent_len; ++i)
            percent = " " + percent;
    }

	std::string res = "|";
	for(int i = 0; i < bar_num; ++i) res += DONE_CHAR;
	for(int i = bar_num; i < BAR_LENGTH; ++i) res += YET_CHAR;
	res += "| " + percent + "%";

	return res;
}
