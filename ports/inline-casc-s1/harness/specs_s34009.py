"""specs_s34009.py - cascade escalation batch 34009: member forwarders 0x4f3230 (+0x6f slot 0x21c), 0x5f2e90 (+0x15 slot 0x50), 0x64f850 (+0xbd slot 0x4c),
null-checked 0x4dbbd0 (+0x54 slot 0x1c) and 0x64fae0 (+0xbd slot 0xc; member null in half the cases), and 0x5f1bc0 (ecx = [[this+0xc]+4], tail 0x5fbac0 hooked).
Unaligned member pointers are written bytewise; slots are recorder stubs (ECX and 2 stack args recorded)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _fwd(fo, slot, cond):
    def g(c):
        clear_hooks(c)
        r = c.rng
        me = rnd(c, 0x400)
        if cond and r.random() < 0.5:
            inner = 0
        else:
            inner = obj(c, 0x40, {slot: pystub(c, 2, ret=r.getrandbits(32), this=True)})
        c.emu.wbytes(me + fo, inner.to_bytes(4, 'little'))
        return [me, r.getrandbits(32), r.getrandbits(32)]
    return g


def _g5f1bc0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5fbac0, 1, ret=r.getrandbits(32), this=True)
    me = rnd(c, 0x40)
    mid = rnd(c, 0x20)
    c.emu.w32(me + 0xc, mid)
    c.emu.w32(mid + 4, rnd(c, 0x20))
    return [me, r.getrandbits(32)]


S(0x4f3230, 'GUESS member +0x6f slot 0x21c forward', 'thiscall', None, ret='eax', gen=_fwd(0x6f, 0x21c, False), note='batch34009')
S(0x5f2e90, 'GUESS member +0x15 slot 0x50 forward', 'thiscall', None, ret='eax', gen=_fwd(0x15, 0x50, False), note='batch34009')
S(0x64f850, 'GUESS member +0xbd slot 0x4c forward', 'thiscall', None, ret='eax', gen=_fwd(0xbd, 0x4c, False), note='batch34009')
S(0x4dbbd0, 'GUESS member +0x54 null-checked slot 0x1c forward', 'thiscall', None, ret='eax', gen=_fwd(0x54, 0x1c, True), note='batch34009')
S(0x64fae0, 'GUESS member +0xbd null-checked slot 0xc forward', 'thiscall', None, ret='eax', gen=_fwd(0xbd, 0xc, True), note='batch34009')
S(0x5f1bc0, 'GUESS chain [[this+0xc]+4] tail 0x5fbac0', 'thiscall', None, ret='eax', gen=_g5f1bc0, note='batch34009')
