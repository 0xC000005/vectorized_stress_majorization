#include "stdafx.h"
#include "ShortestPath.h"
using namespace std;

ShortestPath::ShortestPath(int max)
{
	this->maxint = max;
}

ShortestPath::~ShortestPath()
{
}



// n -- n nodes
// v -- the source node
// dist[] -- the distance from the ith node to the source node
// prev[] -- the previous node of the ith node
// c[][] -- every two nodes' distance
void ShortestPath::Dijkstra(int n, int v, int *dist, int *prev, MatrixXf c)
{
	int *s = new int[n];    // �ж��Ƿ��Ѵ���õ㵽S������
	for (int i = 0; i < n; i++)
	{
		dist[i] = c(v, i);
		s[i] = 0;     // ��ʼ��δ�ù��õ�
		if (dist[i] == maxint)
			prev[i] = 0;
		else
			prev[i] = v;
	}
	dist[v] = 0;
	s[v] = 1;

	// ���ν�δ����S���ϵĽ���У�ȡdist[]��Сֵ�Ľ�㣬������S��
	// һ��S����������V�ж��㣬dist�ͼ�¼�˴�Դ�㵽������������֮������·������
	// ע���Ǵӵڶ����ڵ㿪ʼ����һ��ΪԴ��
	for (int i = 1; i < n; i++)
	{
		int tmp = maxint;
		int u = v;
		// �ҳ���ǰδʹ�õĵ�j��dist[j]��Сֵ
		for (int j = 0; j < n; j++)
		if ((!s[j]) && dist[j]<tmp)
		{
			u = j;              // u���浱ǰ�ڽӵ��о�����С�ĵ�ĺ���
			tmp = dist[j];
		}
		s[u] = 1;    // ��ʾu���Ѵ���S������

		// ����dist
		for (int j = 0; j < n; j++)
		if ((!s[j]) && c(u, j)<maxint)
		{
			int newdist = dist[u] + c(u, j);
			if (newdist < dist[j])
			{
				dist[j] = newdist;
				prev[j] = u;
			}
		}
	}
}


//undirected, weight = 1 if the two vertexes is neighbour
MatrixXf ShortestPath::edgelistToShortestPath(int n, Edges& edgelist) {
	 
	int *dist = new int[n];     // ��ʾ��ǰ�㵽Դ������·������ 
	MatrixXf c(n, n);			// ��¼ͼ�������·������ �ڽӾ���  
	int *prev = new int[n];     // ��¼��ǰ���ǰһ�����
	 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c(i, j) = maxint; 
		}
	}
	//building the adjacency matrix c
	int sourceid = -1;
	int targetid = -1;
	for (int i = 0; i < edgelist.size(); i++)
	{
		sourceid = edgelist[i].first;
		targetid = edgelist[i].second;
		c(sourceid, targetid) = 1;
		c(targetid, sourceid) = 1; 
	}

	initToMaxint(maxint, n, dist);

	for (int i = 0; i < n; i++) {
		Dijkstra(n, i, dist, prev, c);
		for (int j = 0; j < n; j++) {
			c(i, j) = dist[j];
		}
		initToMaxint(maxint, n, dist);
	}

	return c;
}

void ShortestPath::initToMaxint(int maxint, int n, int*& dist) {
	for (int i = 0; i < n; i++)
	{
		dist[i] = maxint;

	}
}