s = input()
if not "::" in s:
  first = ['0000' if not b else b.zfill(4) for b in s.split(":")]
  print(':'.join(first))
else:
  x, y = s.split("::")
  first = [ '0000' if not b else b.zfill(4) for b in x.split(":")]
  second = [ '0000' if not b else b.zfill(4) for b in y.split(":")]
  cnt = 8 - len(first) - len(second)
  for i in range(cnt):
    first.append('0000')
  first.extend(second)
  ans = ':'.join(first)
  print(ans)
