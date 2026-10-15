from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    new_value = rnd(c, 0x20)
    src_inner = obj(c, 0x20, {0x24: pystub(c, 0, this=True, ret=new_value),
                              0x28: pystub(c, 0, this=True)}, nslots=0x28 // 4 + 1)
    dst_inner = obj(c, 0x20, {0x24: pystub(c, 0, this=True, ret=rnd(c, 0x20)),
                              0x28: pystub(c, 0, this=True)}, nslots=0x28 // 4 + 1)
    dst, src = rnd(c, 0x10), rnd(c, 0x10)
    same = r.random() < 0.1
    if same:
        src = dst
    dst_type, src_type = r.choice([0, 1, 4]), r.choice([0, 1, 4])
    e.w32(dst, dst_inner)
    e.w8(dst + 4, dst_type)
    src_value = src_inner if src_type == 4 else r.choice([src_inner, rnd(c, 0x20)])
    e.w32(src, src_value)
    e.w8(src + 4, src_type)
    return [dst, src]


S(0x5f3bf0, 'GUESS replace tagged pointer and release old value', 'thiscall', None,
  ret='eax', gen=gen, note='batch62104')
