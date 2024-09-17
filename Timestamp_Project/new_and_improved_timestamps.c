#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MX_FILENAME_LEN 255 / sizeof(char)

size_t getLineCount(FILE *countFile);
size_t getLongestLine(FILE *longestLineFile);
int getNonDigitCharCount(char *dateString);
char **file2Arr(FILE *file, size_t numLines, size_t maxLength);
void dateStr2Int(char *dateStr, int dateIntArr[], size_t longestLine, int nonDigits, int timeUnits);
long int timeStamptoSeconds(int dateTime[]);
void bubbleSort(char **stringArr, long int secondsArr[], int **unitArr, size_t arrLen, size_t elemLen);

int main(void)
{
        
        // get user input
        char inputFile[MX_FILENAME_LEN];

        while (true)
        {
                puts("please enter the name of the input file: ");
                scanf("%s", inputFile);

                FILE *targetFile = fopen(inputFile, "r");

                if (targetFile == NULL)
                {
                        puts("file does not exist.");
                        continue;
                }
                else
                        break;
        }
        
        // get data from file and create an array
        FILE *targetFile = fopen(inputFile, "r");

        size_t lineCount = getLineCount(targetFile);
        fseek(targetFile, 0, SEEK_SET); // Reset the file pointer to the beginning

        size_t longestLineLength = getLongestLine(targetFile);
        fseek(targetFile, 0, SEEK_SET); 

        char **fileArr = file2Arr(targetFile, lineCount, longestLineLength);

        fclose(targetFile);

        // get the number of nonDigitChars and timeUnits
        int nonDigitCharCount = getNonDigitCharCount(fileArr[0]);
        int timeUnitsCount = nonDigitCharCount + 1;

        
        // dynamically create arr for date integers
        int **dateInts = malloc(sizeof(int *) * lineCount);
        for (size_t i = 0; i < lineCount; ++i)
                dateInts[i] = malloc(sizeof(int) * timeUnitsCount);

        for (size_t i = 0; i < lineCount; ++i)
                dateStr2Int(fileArr[i], dateInts[i], longestLineLength, nonDigitCharCount, timeUnitsCount);

        // create an arr of time in seconds
        long int *timeSeconds = malloc(sizeof(long int) * lineCount);

        for (size_t i = 0; i < lineCount; ++i)
        {
                timeSeconds[i] = timeStamptoSeconds(dateInts[i]);
        }

        // sort all arrs according to time in seconds
        bubbleSort(fileArr, timeSeconds, dateInts, lineCount, longestLineLength);
        
        // free timeSeconds
        free(timeSeconds);

        // save sorted dates to file
        FILE *outputFile = fopen("sorted_dates.txt", "w");
        
        if (outputFile == NULL)
        {
                printf("Unable to write to file");
                return 1;
        }

        for (size_t i = 0; i < lineCount; ++i)
        {
                fprintf(outputFile, "%s\n", fileArr[i]);
        }

        fclose(outputFile);

        // print out 2016 dates
        for (size_t i = 0; i < lineCount; ++i)
        {
                if (dateInts[i][2] == 2016)
                {
                        printf("%s\n", fileArr[i]);
                }
        }


        // Free dateInts
        for (size_t i = 0; i < lineCount; ++i)
        {
                free(dateInts[i]);
        }
        free(dateInts);

        // Free fileArr
        for (size_t i = 0; i < lineCount; ++i)
        {
                free(fileArr[i]);
        }
        free(fileArr);

}

char **file2Arr(FILE *file, size_t numLines, size_t maxLength)
{
        char **stringArr = malloc(sizeof(char *) * numLines);
        char *buffer = malloc(sizeof(char) * maxLength);

        size_t buffStringLen = 0;

        for (size_t i = 0; i < numLines; ++i)
        {
                fgets(buffer, maxLength, file);

                buffStringLen = strlen(buffer);
                buffer[buffStringLen - 1] = '\0';

                stringArr[i] = malloc(sizeof(char) * buffStringLen);

                strcpy(stringArr[i], buffer);
        }

        free(buffer);

        return stringArr;
}

size_t getLineCount(FILE *countFile)
{
        size_t currentLine = 0;
        int c;

        do
        {
                c = fgetc(countFile);
                if (c == '\n')
                        ++currentLine;
        } while (c != EOF);

        return currentLine;
}

size_t getLongestLine(FILE *longestLineFile)
{
        int c;
        size_t currentLineLen = 0;
        size_t longestLineLen = 0;

        while ((c = fgetc(longestLineFile)) != EOF)
        {
                currentLineLen = 1;

                while (c != '\n')
                {
                        c = fgetc(longestLineFile);
                        ++currentLineLen;
                }

                if (currentLineLen > longestLineLen)
                {
                        longestLineLen = currentLineLen;
                }
        }

        return longestLineLen + 1;
}

void dateStr2Int(char *dateStr, int dateIntArr[], size_t longestLine, int nonDigits, int timeUnits)
{
        void slice(const char* str, char* result, size_t start, size_t end);

        char *dateNums = malloc(sizeof(char) * (longestLine - nonDigits));

        char **dateNumsDivided = malloc(sizeof(char *) * timeUnits);
        for (size_t i = 0; i < timeUnits; ++i)
        {
                // longest possible unit of time is a year: 4 + 1 (null terminator) 
                dateNumsDivided[i] = malloc(sizeof(char) * 5); 
        }

        size_t i = 0;
        size_t j = 0;

        while (dateStr[i] != '\0')
        {
                if (isdigit(dateStr[i]))
                {
                        dateNums[j] = dateStr[i];
                        ++j;
                }
                ++i;
        }

        dateNums[longestLine - nonDigits] = '\0';

        // slice string by unit

        slice(dateNums, dateNumsDivided[0], 0, 2);
        slice(dateNums, dateNumsDivided[1], 2, 4);
        slice(dateNums, dateNumsDivided[2], 4, 8);
        slice(dateNums, dateNumsDivided[3], 8, 10);
        slice(dateNums, dateNumsDivided[4], 10, 12);
        slice(dateNums, dateNumsDivided[5], 12, 14);

        // free dateNums
        free(dateNums);

        // convert string to number
        for (size_t i = 0; i < 6; ++i)
        {
                char *endPtr;
                dateIntArr[i] = (int)strtol(dateNumsDivided[i], &endPtr, 0);
        }

        // free dateNumsDivided

        for (size_t i = 0; i < timeUnits; ++i)
        {
                free(dateNumsDivided[i]);
        }

        free(dateNumsDivided);

}


void slice(const char* str, char* result, size_t start, size_t end)
{
    strncpy(result, str + start, end - start);
    result[end - start] = '\0';
}

int getNonDigitCharCount(char *dateString)
{
        size_t i = 0;
        int nonDigitCharCount = 0;

        while (dateString[i] != '\0')
        {
                if (!isdigit(dateString[i]))
                        ++nonDigitCharCount;

                ++i;
        }

        return nonDigitCharCount;
}

long int timeStamptoSeconds(int dateTime[])
{
        int timeStart[] = {1, 1, 2000, 0, 0, 0};
        int timeDiff[] = {0, 0, 0, 0, 0, 0};

        long int timeInSeconds = 0;

        for (size_t i = 0; i < 6; ++i)
        {
                timeDiff[i] = dateTime[i] - timeStart[i];
        }

        //days 
        timeInSeconds += (timeDiff[0] * 24 * 60 * 60);
        
        // months
        timeInSeconds += (timeDiff[1] * (365.25 / 12) * 24 * 60 * 60);
        
        // years
        timeInSeconds += (timeDiff[2] * 31557600);

        // hours
        timeInSeconds += (timeDiff[3] * 60 * 60);

        // minutes 
        timeInSeconds += (timeDiff[4] * 60);

        // seconds
        timeInSeconds += timeDiff[5];

        return timeInSeconds;
}

void bubbleSort(char **stringArr, long int secondsArr[], int **unitArr, size_t arrLen, size_t elemLen)
{
        char *tempStr = malloc(sizeof(char) * elemLen);
        long int tempInt = 0;

        for (size_t i = 0; i < arrLen; ++i)
        {
                for (size_t j = 0; j < (arrLen - 1); ++j)
                {
                        if (secondsArr[j] > secondsArr[j + 1]) 
                        {
                                tempInt = secondsArr[j];
                                secondsArr[j] = secondsArr[j + 1];
                                secondsArr[j + 1] = tempInt;


                                for (size_t k = 0; k < 6; ++k)
                                {
                                        int tempUnit = unitArr[j][k];
                                        unitArr[j][k] = unitArr[j + 1][k];
                                        unitArr[j + 1][k] = tempUnit;
                                        
                                }

                                strcpy(tempStr, stringArr[j]);
                                strcpy(stringArr[j], stringArr[j + 1]);
                                strcpy(stringArr[j + 1], tempStr);
                        }
                }
        }

        free(tempStr);
}
