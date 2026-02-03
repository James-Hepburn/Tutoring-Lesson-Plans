def check_violation(student, condition, group, condition_type):
    violations = 0
    if student in condition:
        pairs = condition[student]
        for i in pairs:
            if i not in group and condition_type == "same":
                violations += 1
            if i in group and condition_type == "diff":
                violations += 1
    return violations

x = int(input())
same_groups = {}
for i in range(x):
    name1, name2 = input().split()
    if name1 in same_groups:
        same_groups[name1].append(name2)
    else:
        same_groups[name1] = [name2]

y = int(input())
diff_groups = {}
for i in range(y):
    name1, name2 = input().split()
    if name1 in diff_groups:
        diff_groups[name1].append(name2)
    else:
        diff_groups[name1] = [name2]

g = int(input())
real_groups = []
for i in range(g):
    real_groups.append(input().split())

violations = 0

for i in real_groups:
    student1 = i[0]
    student2 = i[1]
    student3 = i[2]

    violations += check_violation(student1, same_groups, i, "same")
    violations += check_violation(student1, diff_groups, i, "diff")
    violations += check_violation(student2, same_groups, i, "same")
    violations += check_violation(student2, diff_groups, i, "diff")
    violations += check_violation(student3, same_groups, i, "same")
    violations += check_violation(student3, diff_groups, i, "diff")

print(violations)
