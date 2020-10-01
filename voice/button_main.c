#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include "./button_getdata.h"
#include "./button_out.h"
#include "./common.h"

/* ユーザ定義関数の宣言 */
static void SignalHandlerTime(int SignalName);
/* ユーザ定義関数の宣言 */
static void SetSignal(int SignalName);
static void SigHandler(int SignalName);

static int change_mode();
static void change_button();

int PUSH_BUTTON;

int main(){
	
	PUSH_BUTTON = AMPLFER;
	struct sigaction action;
	
	
	
	struct itimerval timer;
	/* シグナルの設定 */
	action.sa_handler = SignalHandlerTime;
	action.sa_flags = SA_RESTART;
	sigemptyset(&action.sa_mask);
	sigaction(SIGALRM, &action, NULL);
	
	/* set intarval timer (500ms) */
	timer.it_value.tv_sec = 0;
	timer.it_value.tv_usec = MILLI_SEC;
	timer.it_interval.tv_sec = 0;
	timer.it_interval.tv_usec = MILLI_SEC;
	if(setitimer(ITIMER_REAL, &timer, NULL) < 0){
		perror("setitimer error");
		exit(1);
	}
	
	SetSignal( SIGINT );
	
	while(1){
		out_voice( get_data(PUSH_BUTTON) );
	}
	
	return 0;
	
}

int change_mode(){
	static int num = 0;
	num++;
	if(num == 10){
		if(PUSH_BUTTON == AMPLFER){
			PUSH_BUTTON = SILENT;
			num = 0;
		}
	}else if(PUSH_BUTTON == SILENT){
		num = 0;
	}
}

void change_button(){
	if(PUSH_BUTTON == SILENT){
		PUSH_BUTTON = AMPLFER;
	}else{
		PUSH_BUTTON = SILENT;
	}
}

/* シグナル受信/処理 */
void SignalHandlerTime(int p_signame)
{
	struct sigaction action;
	/* シグナルの設定 */
	change_mode();
	/* シグナルの再設定 */
	action.sa_handler = SignalHandlerTime;
	action.sa_flags = SA_RESTART;
	sigemptyset(&action.sa_mask);
	sigaction(SIGALRM, &action, NULL);
	return;
}

/* シグナル受信/処理 */
void SignalHandler(int p_signame)
{
	change_button();
	return;
}

/* シグナルの設定 */
void SetSignal(int p_signame)
{
	if (signal(p_signame,SignalHandler) == SIG_ERR) {
		/* シグナル設定エラー  */
		perror("SetSignal()");
	}
	return;
}
