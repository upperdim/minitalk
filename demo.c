#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum, siginfo_t* info, void* context) {
	(void) context;
	(void) info;
	write(STDOUT_FILENO, "Nope!\n", 6);
	printf("\nSignal handler function called %d\n", signum);
}

int main() {
	printf("Use `kill -9 <pid>` to close this program, you might need it.\n");
	// signal(SIGINT, handler); // Ctrl+C
	
	struct sigaction sigact;
	sigact.sa_sigaction = handler;
	
	while (1) {
		sigaction(SIGINT, &sigact, NULL);
		printf("Waste CPU cycles... for educational purpses... pid = %d\n", getpid());
		sleep(1);
	}
}
