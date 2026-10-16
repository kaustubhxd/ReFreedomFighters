"""specs_s927.py - unclaimed-09 batch 19 (docs/20-unclaimed-09.md, claim 21): ZItemAmmo::Load(ZLoadGame*).

The object is 0x100 random bytes. 0x46f520 is hooked (unverified callee): it logs its object pointer (heap) and argument
(the loader, heap), and returns a random bool in al, with a plain ret 4 (thiscall, one argument). The loader is a fake
object whose slot 0x48 writes a random dword at its pointer argument and logs the value."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng
    ok = rng.getrandbits(1)
    v = rng.getrandbits(32)

    def hook46(e2, r):
        e2.calllog.append(('Call46f520', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(eax=ok, argbytes=4)

    def h48(e2, r):
        e2.calllog.append(('L48', v))
        e2.w32(e2.arg32(0), v)
        e2.ret(argbytes=4)

    e.hook(0x46f520, hook46)
    ld = e.fake_object('itemammo_loader', 0x40, slots={0x48: h48})
    return [_rnd(c, 0x100), ld]


S(0x46f5a0, 'ZItemAmmo::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-09 b19; residue-10 fallback; 0x46f520 hooked, loader slot 0x48 stubbed (unverified callees)')
