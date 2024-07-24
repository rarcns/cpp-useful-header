#include <iostream>
#include <Windows.h>
#include <string>
void waitForEnter() {
    std::cout << "続行するには Enter キーを押してください..." << std::endl;
    std::cin.get(); // ユーザーが Enter を押すまで待機します
    exit(1);
}
void SetConsoleColor(WORD color) {
    // コンソール出力の色を変えるためのもの。
    // 例：
    // SetConsoleColor(11);//青色にする
    // SetConsoleColor(7);//色をリセットする
    // リセットが必須
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
void Open_Website(std::string Link) {
    // サイトを開く物。使用例
    // Open_Website("https://rarcns.github.io/Rar-tools-page/");
    // リンクの部分はご自由に変えてください
    system(("start " + Link).c_str());
}

//askシリーズの使い方

/*
まず、値を格納するものを宣言する。
使用用途によって異なるが、string,int,unsigned charなどで宣言する。また、宣言している型式によってaskを使い分ける

例：intの場合
int abc;   //宣言を行う
intask("質問内容はstring" , abc);//今回の例はintであるため、intaskを使う
任意で、
    if(abc == 1){
        std::cout << "you typed 1";
    }
などに応用できる。

ほかの使い方などで、ヘルプが必要な場合はgithubリポジトリにissueを投げるか、twitter(@RarRcns)までDMを投げてください。また、discord(rar_burn)にDMを送ることもできます。対応が早いのはtwitterです。
*/
void ask(const std::string question, std::string& retur) {//string版のask
    std::cout << question;
    std::getline(std::cin, retur);
}
void intask(const std::string& question, int& retur) {
    std::string input;
    std::cout << question;
    std::getline(std::cin, input);
    retur = std::stoi(input); // std::stoiを使用して文字列を整数に変換
}
void ucharask(const std::string& question, unsigned char& retur) {
    std::string input;
    std::cout << question;
    std::getline(std::cin, input);

    try {
        int value = std::stoi(input); // 入力を整数に変換
        if (value < 0 || value > 255) {
            throw std::out_of_range("unsigned charの範囲外の値です。\nエラーコード[UCAS-OV-255]");
        }
        retur = static_cast<unsigned char>(value); // 整数をunsigned charに変換
    }
    catch (const std::invalid_argument&) {
        std::cerr << "無効な入力です。\nエラーコード[UCAS-INV-ARG]" << std::endl;
    }
    catch (const std::out_of_range&) {
        std::cerr << "範囲外の値です。\nエラーコード[UCAS-OV-RG]" << std::endl;
    }
}

void dwask(const std::string& question, DWORD& retur) {
    std::string input;
    std::cout << question;
    std::getline(std::cin, input);

    try {
        retur = std::stoul(input); // 入力をunsigned longに変換し、それをDWORDに設定
    }
    catch (const std::invalid_argument&) {
        std::cerr << "無効な入力です\nエラーコード[DW-INV-ARG]。" << std::endl;
    }
    catch (const std::out_of_range&) {
        std::cerr << "範囲外の値です。\nエラーコード[DW-OV-RG]" << std::endl;
    }
}

void byteask(const std::string& question, BYTE& retur) {
    std::string input;
    std::cout << question;
    std::getline(std::cin, input);

    try {
        int value = std::stoi(input); // 入力を整数に変換
        if (value < 0 || value > 255) {
            throw std::out_of_range("BYTEの範囲外の値です。\nエラーコード[BYTE-OV255]");
        }
        retur = static_cast<BYTE>(value); // 整数をBYTEに変換
    }
    catch (const std::invalid_argument&) {
        std::cerr << "無効な入力です。\nエラーコード[BYTE-INV-ARG]" << std::endl;
    }
    catch (const std::out_of_range&) {
        std::cerr << "範囲外の値です。\nエラーコード[BYTE-OV-RG]" << std::endl;
    }
}
