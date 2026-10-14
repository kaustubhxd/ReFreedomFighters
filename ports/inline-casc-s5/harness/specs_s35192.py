"""specs_s35192.py - 0x4c75a0 (thiscall, no args, ret=None). Engine (0x2000 bytes): unaligned dword [+0x1907] = input object I with slot 0x38 (2 args recorded; per call returns a result from a list of eleven, true in 1/3 each, with garbage upper bytes); table +0xadc -> manager with dword +0x30 random. this: 0x80 random bytes: bytes +0x50 / +0x54 (0, 1 or random), +0x44 -> object with slot 0xb4
(logs only the low byte of its argument: the original pushes edx whose upper bytes are leftovers), float +0x48 equal to the constant at 0x6785d0 in 1/3, else random or NaN. The eight helpers 4c8760, 4c85f0, 4c8560, 4c86d0, 4c7bb0, 4c7330, 4c8360, 4c6cf0 hooked (thiscall, 0 args)."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g4c75a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    res = [((r.getrandbits(24) << 8) | 1) if r.random() < 1 / 3 else (r.getrandbits(24) << 8) for _ in range(11)]
    kc = [0]

    def hkey(em, res_):
        em.calllog.append(('key', em.reg('ecx'), em.arg32(0), em.arg32(1)))   # all eleven calls, not only the last recorder rows
        v = res[min(kc[0], 10)]
        kc[0] += 1
        em.ret(eax=v, argbytes=8)
    I = obj(c, 0x20, {0x38: e.stub_fn('key', hkey)}, nslots=0x20)
    so = sysobj(c, table_size=0xae0)
    e.wbytes(so + 0x1907, I.to_bytes(4, 'little'))
    tab = e.r32(so + 0x9b)
    mgr = rnd(c, 0x40)
    e.w32(tab + 0xadc, mgr)

    def hb4(em, res_):
        em.calllog.append(('b4', em.arg32(0) & 0xff))
        em.ret(argbytes=4)
    cobj = obj(c, 0x20, {0xb4: e.stub_fn('b4', hb4)}, nslots=0x30)
    me = rnd(c, 0x80)
    e.w8(me + 0x50, r.choice([0, 1, r.getrandbits(8)]))
    e.w8(me + 0x54, r.choice([0, 1, r.getrandbits(8)]))
    e.w32(me + 0x44, cobj)
    K = e.r32(0x6785d0)
    e.w32(me + 0x48, K if r.random() < 1 / 3 else r.choice([0x7fc00000, 0, 0x80000000, r.getrandbits(32)]))
    for a in (0x4c8760, 0x4c85f0, 0x4c8560, 0x4c86d0, 0x4c7bb0, 0x4c7330, 0x4c8360, 0x4c6cf0):
        hook_rec(c, a, 0, this=True, pop=0)
    return [me]


S(0x4c75a0, 'GUESS poll debug key bindings and run toggles', 'thiscall', None, ret=None, gen=_g4c75a0, nan_heap=True, note='batch35192')
