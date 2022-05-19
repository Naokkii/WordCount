#include <stdio.h>
#include <string.h>

int countChar(char *filename){
    FILE *fp;  // ָ���ļ���ָ��
    char buffer[1000];  //���������洢��ȡ����ÿ�е�����
    int bufferLength;  // ��������ʵ�ʴ洢�����ݵĳ���
    int i;  // ��ǰ�����������ĵ�i���ַ�
    char c;  // ��ȡ�����ַ�
    int charNumber = 0;  // ��ǰ�е��ַ���
    int charCount = 0;
    if( (fp=fopen(filename, "rt")) == NULL ){
        perror(filename);
        return -1;
    }
    // ÿ�ζ�ȡһ�����ݣ����浽buffer��ÿ�����ֻ����1000���ַ�
    while(fgets(buffer, 1000, fp) != NULL){
        bufferLength = strlen(buffer);
        // ����������������
        for(i=0; i<bufferLength; i++){
            c = buffer[i];
            if(c!=NULL){
                charNumber++;
            }
        }
        // һ�н������������ַ���
        charCount += charNumber;  // ���ַ���
        // ���㣬����ͳ����һ��
        charNumber = 0;
    }
    fclose(fp);
    return charCount;
}

int countWord(char *filename){
    FILE *fp;  // ָ���ļ���ָ��
    char buffer[1000];  //���������洢��ȡ����ÿ�е�����
    int bufferLength;  // ��������ʵ�ʴ洢�����ݵĳ���
    int i;  // ��ǰ�����������ĵ�i���ַ�
    char c;  // ��ȡ�����ַ�
    int isBlank = 0;  // �ϸ��ַ��Ƿ��ǿո�
    int wordNumber = 0; // ��ǰ�еĵ�����
    int wordCount = 0;
    if( (fp=fopen(filename, "rt")) == NULL ){
        perror(filename);
        return -1;
    }
    // ÿ�ζ�ȡһ�����ݣ����浽buffer��ÿ�����ֻ����1000���ַ�
    while(fgets(buffer, 1000, fp) != NULL){
        bufferLength = strlen(buffer);
        // ����������������
        for(i=0; i<bufferLength; i++){
            c = buffer[i];
            if( c==' ' || c=='\t'){  // �����ո�
                !isBlank && wordNumber++;  // ����ϸ��ַ����ǿո���ô��������1
                isBlank = 1;
            }
            else{
            	isBlank = 0;
			}
        }
        !isBlank && wordNumber++;  // ������һ���ַ����ǿո���ô��������1
        isBlank = 1;  // ÿ�λ�������Ϊ1
        // һ�н����������ܵ�����
        wordCount += wordNumber;  // �ܵ�����
        // ���㣬����ͳ����һ��
        wordNumber = 0;
    }
    fclose(fp);
    return wordCount;
}

int main(int argc, char* argv[]) {
	if(strcmp(argv[1],"-c")==0||strcmp(argv[1],"-C")==0)
	{
		printf("ͳ���ַ�������\n");
		printf("�ַ�����%d\n",countChar(argv[2]));
	}
	if(strcmp(argv[1],"-w")==0||strcmp(argv[1],"-W")==0)
	{
		printf("ͳ�Ƶ��ʸ�����\n");
		printf("��������%d\n",countWord(argv[2]));
	}
	return 0;
}

