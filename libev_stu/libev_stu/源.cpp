
// libev��Ҫ��ͷ�ļ�
#include <ev.h>
#include <stdio.h>

// �������Ǹո�˵����Ҫ�������¼�����Щ�¼�������libev�ṩ��
// with the name ev_TYPE
//ev_io��ev_timer��Ϊ���ã�ev_ioΪ��������̨���룬ev_timerΪʱ���¼�
ev_io stdin_watcher;
ev_timer timeout_watcher;

// ����Ϊ�Զ���Ļص������������������¼�ʱ������ִ�ж�Ӧ�ĺ���

// ev_io�¼��Ļص�����������������stdinʱ�����ú���
static void stdin_cb(EV_P_ ev_io *w, int revents)
{
	puts("stdin ready");
	//��ev_io�¼��ļ�ز����Զ�ֹͣ����Ҫ�ֶ�����Ҫ��ʱ��ֹͣ
	ev_io_stop(EV_A_ w);

	//�����loop�¼������м��ֹͣʱֹͣ��Ҳ�����ֶ��ر�ȫ����ev_run
	ev_break(EV_A_ EVBREAK_ALL);
}

// ʱ���¼����Զ���ص��������ɶ�ʱ����
static void timeout_cb(EV_P_ ev_timer *w, intrevents)
{
	puts("timeout");
	//�ر������һ���������е�ev_run
	ev_break(EV_A_ EVBREAK_ONE);
}

int main(void)
{
	//����Ĭ�ϵ� event loop��������һ��������������װ���źܶ��¼���ͣ����
	struct ev_loop *loop = EV_DEFAULT;

	// ��ʼ��ev_io�¼���أ��������Ļص���������stdin
	ev_io_init(&stdin_watcher, stdin_cb,/*STDIN_FILENO*/ 0, EV_READ);
	//��ev_io�¼��ŵ�event loop��������
	ev_io_start(loop, &stdin_watcher);

	// ��ʼ��ev_timer�¼���أ��������Ļص����������ʱ�䣬�Ƿ��ظ�
	ev_timer_init(&timeout_watcher, timeout_cb, 5.5, 0.);
	//��ev_timer�¼��ŵ�event loop��������
	ev_timer_start(loop, &timeout_watcher);

	// �����ǵĴ�����event loop������������
	ev_run(loop, 0);

	// ev_run���н���֮�󣬲Ż����е�����
	return 0;
}

��������������������������������
��Ȩ����������ΪCSDN������cinyaaaa����ԭ�����£���ѭ CC 4.0 BY - SA ��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https ://blog.csdn.net/cxy450019566/article/details/52606512/