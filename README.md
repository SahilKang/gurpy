# gurpy
Python extension for libgur

```python
import gurpy as gp

hello = gp.a4 + gp.e1 + gp.h4 + ' ' + gp.a4 + gp.h5 + gp.j2 + ' ' + gp.a2 + gp.b1 + gp.h3 + gp.g3
  >'ਸਤਿ ਸੀ੍ ਅਕਾਲ'

world = gp.e3 + gp.i1 + gp.e5 + gp.h5 + gp.a2 + gp.h3
  >'ਦੁਨੀਅਾ'

hello_world = hello + ' ' + world + gp.q1
  >'ਸਤਿ ਸੀ੍ ਅਕਾਲ ਦੁਨੀਅਾ।'

gp.letters(hello_world)
  >'ਸਤਸਅਕਲਦਨਅ'

tuple(gp.accents(hello_world))
  >('ਿ', 'ੀ', '੍', 'ਾ', 'ੁ', 'ੀ', 'ਾ')

gp.puncs(hello_world)
  >'।'

tuple(gp.comp(hello_world))
  >('ਅ', 'ਸ', 'ਕ', 'ਤ', 'ਦ', 'ਨ', 'ਲ', 'ਾ', 'ਿ', 'ੀ', 'ੁ', '੍', '।', ' ')

tuple(world)
  >('ਦ', 'ੁ', 'ਨ', 'ੀ', 'ਅ', 'ਾ')

tuple(gp.clobber(world))
  >('ਦ', 'ੁ', 'ਨ', 'ੀ', 'ਆ')
```
