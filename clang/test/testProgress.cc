// 作成 - 2019/03/17 堀哲也

#include <gtest/gtest.h>
#include "../src/progress.h"

TEST(ProgressBarTest, constructTest)
{
    using ryhoh_prgr::Progress;
    Progress progress = Progress(10);
    ASSERT_EQ(progress.getMax(), 10);
    ASSERT_EQ(progress.getPos(),  0);
}

TEST(ProgressBarTest, generateStringTest)
{
    using ryhoh_prgr::Progress;
    Progress progress = Progress(10);
    ASSERT_EQ(
        progress.generateString(),
        "|--------------------|   0%    NUM:[ 0 / 10 ]"
    );
}

TEST(ProgressBarTest, clickTest)
{
    using ryhoh_prgr::Progress;
    Progress progress = Progress(10);

    progress.click();
    progress.click();
    ASSERT_EQ(
        progress.generateString(),
        "|****----------------|  20%    NUM:[ 2 / 10 ]"
    );

    progress.click();
    ASSERT_EQ(
        progress.generateString(),
        "|******--------------|  30%    NUM:[ 3 / 10 ]"
    );

    for (int i=3; i<11; ++i)
        progress.click();
    ASSERT_EQ(
        progress.generateString(),
        "|********************| 100%    NUM:[ 10 / 10 ]"
    );
}

TEST(SimpleProgressTest, constructTest)
{
    using ryhoh_prgr::Progress;
    using ryhoh_prgr::SimpleProgress;
    Progress *progress = new SimpleProgress(10);
    ASSERT_EQ(progress->getMax(), 10);
    ASSERT_EQ(progress->getPos(),  0);
}

TEST(SimpleProgressTest, generateStringTest)
{
    using ryhoh_prgr::Progress;
    using ryhoh_prgr::SimpleProgress;
    Progress *progress = new SimpleProgress(10);
    ASSERT_EQ(
        progress->generateString(),
        "|--------------------|   0%"
    );
    delete progress;
}

TEST(SimpleProgressTest, clickTest)
{
    using ryhoh_prgr::Progress;
    using ryhoh_prgr::SimpleProgress;
    Progress *progress = new SimpleProgress(10);

    progress->click();
    progress->click();
    ASSERT_EQ(
        progress->generateString(),
        "|****----------------|  20%"
    );

    progress->click();
    ASSERT_EQ(
        progress->generateString(),
        "|******--------------|  30%"
    );

    for (int i=3; i<11; ++i)
        progress->click();
    ASSERT_EQ(
        progress->generateString(),
        "|********************| 100%"
    );
}
