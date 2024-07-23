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
void ask(std::string question, std::string retur) {
    std::cout << question;
    std::cin >> retur;
    //使用方法
    // std::string リターンの値を代入する物;
    // ask("質問内容" , リターンの値を代入する物);
    // if(リターンの値を代入する物 == 1){//例として1だった場合にしている
    //std::cout << "abc" << std::endl;
    //}else if(リターンの値を代入する物 == 2){//例として2だった場合にしている
    //std::cout << "abcabc" << std::endl;
    //}
}
