#include <stdio.h>
#include <string.h>

int countChar(char *filename){
    FILE *fp;  // 指向文件的指针
    char buffer[1000];  //缓冲区，存储读取到的每行的内容
    int bufferLength;  // 缓冲区中实际存储的内容的长度
    int i;  // 当前读到缓冲区的第i个字符
    char c;  // 读取到的字符
    int charNumber = 0;  // 当前行的字符数
    int charCount = 0;
    if( (fp=fopen(filename, "rt")) == NULL ){
        perror(filename);
        return -1;
    }
    // 每次读取一行数据，保存到buffer，每行最多只能有1000个字符
    while(fgets(buffer, 1000, fp) != NULL){
        bufferLength = strlen(buffer);
        // 遍历缓冲区的内容
        for(i=0; i<bufferLength; i++){
            c = buffer[i];
            if(c!=NULL){
                charNumber++;
            }
        }
        // 一行结束，计算总字符数
        charCount += charNumber;  // 总字符数
        // 置零，重新统计下一行
        charNumber = 0;
    }
    fclose(fp);
    return charCount;
}

int countWord(char *filename){
    FILE *fp;  // 指向文件的指针
    char buffer[1000];  //缓冲区，存储读取到的每行的内容
    int bufferLength;  // 缓冲区中实际存储的内容的长度
    int i;  // 当前读到缓冲区的第i个字符
    char c;  // 读取到的字符
    int isBlank = 0;  // 上个字符是否是空格
    int wordNumber = 0; // 当前行的单词数
    int wordCount = 0;
    if( (fp=fopen(filename, "rt")) == NULL ){
        perror(filename);
        return -1;
    }
    // 每次读取一行数据，保存到buffer，每行最多只能有1000个字符
    while(fgets(buffer, 1000, fp) != NULL){
        bufferLength = strlen(buffer);
        // 遍历缓冲区的内容
        for(i=0; i<bufferLength; i++){
            c = buffer[i];
            if( c==' ' || c=='\t'){  // 遇到空格
                !isBlank && wordNumber++;  // 如果上个字符不是空格，那么单词数加1
                isBlank = 1;
            }
            else{
            	isBlank = 0;
			}
        }
        !isBlank && wordNumber++;  // 如果最后一个字符不是空格，那么单词数加1
        isBlank = 1;  // 每次换行重置为1
        // 一行结束，计算总单词数
        wordCount += wordNumber;  // 总单词数
        // 置零，重新统计下一行
        wordNumber = 0;
    }
    fclose(fp);
    return wordCount;
}

int main(int argc, char* argv[]) {
	if(strcmp(argv[1],"-c")==0||strcmp(argv[1],"-C")==0)
	{
		printf("统计字符个数！\n");
		printf("字符数：%d\n",countChar(argv[2]));
	}
	if(strcmp(argv[1],"-w")==0||strcmp(argv[1],"-W")==0)
	{
		printf("统计单词个数！\n");
		printf("单词数：%d\n",countWord(argv[2]));
	}
	return 0;
}

