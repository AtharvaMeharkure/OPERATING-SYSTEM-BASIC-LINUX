#include <stdio.h>

int main() {
    int frames, pages;
    
    printf("Enter number of frames: ");
    scanf("%d", &frames);
    
    printf("Enter number of pages: ");
    scanf("%d", &pages);

    int page[pages], frame[frames];
    
    printf("Enter page reference string:\n");
    for(int i = 0; i < pages; i++) {
        scanf("%d", &page[i]);
    }

    for(int i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    int index = 0, pageFault = 0;

    for(int i = 0; i < pages; i++) {
        int found = 0;

        for(int j = 0; j < frames; j++) {
            if(frame[j] == page[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            frame[index] = page[i];
            index = (index + 1) % frames;
            pageFault++;
        }

        printf("Frames: ");
        for(int j = 0; j < frames; j++) {
            printf("%d ", frame[j]);
        }
        printf("\n");
    }

    printf("Total Page Faults = %d\n", pageFault);

    return 0;
}
