
def check_valid(skill, skill_item):
  skill_order = skill
  for alphabet in skill_item:
    if alphabet in skill:
        if skill_order != "" and alphabet != skill_order[0]:
            return False
    skill_order = skill_order[1:]
  return True

def solution(skill, skill_trees): 
  result = 0
  for skill_item in skill_trees:
    if check_valid(skill, skill_item):
      result = result+1
  return result

def
  