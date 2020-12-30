from itertools import combinations

def get_key_list(n_column):
  column = list(range( n_column))
  all_key = []
  for i in map(lambda i: i+1, column):
    all_key.extend(list(combinations(column,i)))
  return all_key

def get_row_by_key(key, row):
  row_by_key = []
  for key_idx in key:
    row_by_key.append(row[key_idx])
  return tuple(row_by_key)

def is_minimality_key(answer, key):
  for candidate_key in answer:
    if set(candidate_key) & set(key) == set(candidate_key):
      return False
  return True
  
def solution(relation):
  answer = []
  n_column = len(relation[0])
  n_row = len(relation)
  key_list = get_key_list(n_column)

  row_by_key = set()
  for key in key_list:
    row_set = set()
    for row in relation:
      row_by_key = get_row_by_key(key, row)
      row_set.add(row_by_key)
    if len(row_set) is n_row:
      if is_minimality_key(answer, key):
        answer.append(key)

  return len(answer)



solution([["100","ryan","music","2"],["200","apeach","math","2"],["300","tube","computer","3"],["400","con","computer","4"],["500","muzi","music","3"],["600","apeach","music","2"]])