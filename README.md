# progressbar
## 用途
C++のコンソール上で時間のかかる処理を行う際に使うプログレスバー

## メソッド一覧
- class Progress
	- Progress(int max)
	- virtual ~Progress();
	- virtual std::string generateString();  プログレスバーの表示
	- void click();  プログレスを1進める
	- int getMax();
	- int getPos();

- class SimpleProgress: public Progress
	- SimpleProgress(int max)
	- virtual ~SimpleProgress();
	- std::string generateString() override;