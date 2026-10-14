"""specs_s35122.py - 0x656e80 (thiscall(a, flags) ret 8, ret='eax'). this vtable slots 0xc (1 arg: returns by call index a value or a record block r), 0x5c (1 arg), 0x50 (two args; returns by call index); r: random 0x60 bytes with the word at +2 zero in 2/3, word +0xe small, dword +0x50 small;
flags low nibble among 0, 8 (only bit 3), 1, 2, 4, random; the assert hook at 0x7003b0 is always set."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g656e80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    rec = rnd(c, 0x60)
    e.wbytes(rec + 2, (0 if r.random() < 2 / 3 else r.getrandbits(16) | 1).to_bytes(2, 'little'))
    e.wbytes(rec + 0xe, r.choice([0, 1, 3, 100, r.getrandbits(16)]).to_bytes(2, 'little'))
    e.w32(rec + 0x50, r.choice([0, 1, 2, 7, r.getrandbits(32)]))
    v1, v2 = r.getrandbits(32), rec
    s0c = [v1, rec, rnd(c, 0x10)]
    s50 = [r.getrandbits(32), r.getrandbits(32)]
    me = obj(c, 0x20, {0xc: pystub(c, 1, this=True, ret=lambda em, k: s0c[min(k, 2)]), 0x5c: pystub(c, 1, this=True, ret=r.getrandbits(32)),
                       0x50: pystub(c, 2, this=True, ret=lambda em, k: s50[min(k, 1)])}, nslots=0x20)
    fl = (r.getrandbits(32) & ~0xf) | r.choice([0, 0, 8, 8, 1, 2, 4, r.getrandbits(4)])
    return [me, r.getrandbits(32), fl]


S(0x656e80, 'GUESS resolve handle and duplicate record buffer', 'thiscall', None, ret='eax', gen=_g656e80, note='batch35122')
