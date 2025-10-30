# 유저는 한 번에 한 명의 유저를 신고 가능 동일 신고는 1회
# k번 이상 신고된 유저는 게시판 이용이 정지되며, 
# 해당 유저를 신고한 모든 유저에게 정지 사실을 메일로 발송합니다.

def solution(id_list, report, k):
    answer = [0] * len(id_list)
    graph = [[] for i in range(len(id_list))]
    for i in report:
        lst = list(i.split())
        if not id_list.index(lst[0]) in graph[id_list.index(lst[1])]:
            graph[id_list.index(lst[1])].append(id_list.index(lst[0]))
        
    for i in graph:
        if len(i) >= k:
            for j in i:
                answer[j] += 1

    
    return answer