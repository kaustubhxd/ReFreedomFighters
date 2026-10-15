"""specs_s38094.py - cascade s8 batch 38094. cdecl(table, key, size) -> entry. Table (0x20 bytes): empty (capacity 0) 25% or capacity 4 / 8 / 16 with entries inserted by the same hash-and-probe rule (names from a small set so
collisions happen), count / threshold (count == threshold 40% of the time: grow path); +0x10 -> allocator {alloc +0, free +8} whose functions are Python stubs (alloc returns a fresh heap buffer and logs the size; free logs the
pointer). The key is an existing name, a new name or an empty string; size 0 (lookup only) 25%. memset (0x634d10) fills and logs; the string hash 0x61fce0 is the real exe code."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks

NAMES = [b'a', b'b', b'ab', b'abc', b'hello', b'xyz', b'q', b'zz', b'name1', b'name2', b'Aa', b'BB', b'']


def _h(s):
    h = 0
    for ch in s:
        h = (h * 33 + ch) & 0xffffffff
    return h


def _g61fd60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def alloc(em, res_):
        sz = em.arg32(0)
        em.calllog.append(('alloc', sz))
        em.ret(eax=0 if r.random() < 0.04 else e.alloc(max(sz, 16), 4), argbytes=0)

    def free(em, res_):
        em.calllog.append(('free', em.arg32(0)))
        em.ret(eax=0, argbytes=0)
    a = e.alloc(0x10, 4)
    e.w32(a, e.stub_fn('alloc', alloc))
    e.w32(a + 8, e.stub_fn('free', free))

    def ms(em, res_):
        p, v, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memset', v, n))
        em.wbytes(p, bytes([v & 0xff]) * n)
        em.ret(eax=p, argbytes=0)
    e.hook(0x634d10, ms)
    strs = {}

    def cstr(nm):
        if nm not in strs:
            p = e.alloc(len(nm) + 1, 1)
            e.wbytes(p, nm + b'\0')
            strs[nm] = p
        return strs[nm]
    t = rnd(c, 0x20)
    e.w32(t + 0x10, a)
    names = r.sample(NAMES, r.randrange(0, 7))
    if r.random() < 0.25:
        e.w32(t, 0)
        e.w32(t + 4, 0)
        e.w32(t + 8, 0)
        names = []
    else:
        n = r.choice([4, 8, 16])
        names = names[:n // 2]
        bk = e.alloc(4 * n, 4)
        arr = [0] * n
        for nm in names:
            ent = rnd(c, 0x10)
            e.w32(ent, cstr(nm))
            i = _h(nm) & (n - 1)
            while arr[i]:
                i = n - 1 if i == 0 else i - 1
            arr[i] = ent
        e.wbytes(bk, struct.pack('<%dI' % n, *arr))
        e.w32(t, bk)
        e.w32(t + 4, n)
        e.w32(t + 8, len(names))
        e.w32(t + 0xc, len(names) if r.random() < 0.4 else n // 2 + 1)
        if len(names) == n // 2 and r.random() < 0.5:
            e.w32(t + 0xc, n // 2)
    if names and r.random() < 0.6:
        key = r.choice(names)
    else:
        key = r.choice(NAMES)
    return [t, cstr(key), r.choice([0, 0x10, 0x14, 0xc, 0xc])]


S(0x61fd60, 'GUESS string hash table find or insert', 'cdecl', None, ret='eax', gen=_g61fd60, note='batch38094')
