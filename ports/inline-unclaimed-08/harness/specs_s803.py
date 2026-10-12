"""specs_s803.py - unclaimed-08 batch 803 (docs/20-unclaimed-08.md): ZFFActor::PullWeapon(int), thiscall, ret 4.

The actor is 0x1000 random bytes whose fields +0x78a and +0x78e are random, with a 30% chance each of being zero (the
log path). Its vtable logs (slot, args): +0x1d8 writes a fake value into the out-pointer argument and returns a random
object; +0x6b4 returns a random bool; +0x6d0 is void. The logger at *0x700390 returns an object whose vtable +0x2c is a
cdecl print (no stack pop). The destructor 0x4cbec0 runs the original code."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _slot(name, off, nargs, impl=None, log_ecx=True, mask=(), pop=True):
    """A vtable slot that logs (name, off, ecx, args). mask: argument indexes not logged (stack addresses differ
    between builds). log_ecx=False for cdecl calls, where ECX is not part of the contract. pop=False: caller pops."""
    def h(e, r):
        args = [e.arg32(k) for k in range(nargs)]
        e.calllog.append((name, off, e.reg('ecx') if log_ecx else None,
                          tuple(None if i in mask else a for i, a in enumerate(args))))
        eax, st0 = impl(e, args) if impl else (0, None)
        e.ret(eax=eax, argbytes=4 * nargs if pop else 0, st0=st0)
    return h


def _pull(c):
    actor = _rnd(c, 0x1000)
    for off in (0x78a, 0x78e):
        v = 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32)
        c.emu.w32(actor + off, v)

    def f1d8(e, a):
        # a[0]: out pointer (the local object), a[1]: flag. Writes the object's own address + 4 as its list head, so
        # the destructor sees an empty list and does not reach the CRT free (0x634273), which faults on fake pointers.
        if c.rng.random() < 0.5:
            e.w32(a[0], a[0] + 4)                       # empty list: the destructor skips the free
        else:
            node = e.alloc(0x10)                         # one node: the destructor calls the CRT free (hooked below)
            e.w32(a[0], node)
        return (msg, None)

    def free_hook(e, r):
        e.calllog.append(('CRT free 0x634273 (hook)', 0x634273, None, (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x634273, free_hook)
    msg = _rnd(c, 0x40)
    e_str = c.emu.alloc(0x20)
    c.emu.w32(msg, e_str)
    vt_actor = c.emu.fake_vtable('ZFFActor', 0x6d4 // 4 + 1, slots={
        0x1d8: _slot('ZFFActor', 0x1d8, 2, f1d8, mask=(0,)),
        0x6b4: _slot('ZFFActor', 0x6b4, 1, lambda e, a: (c.rng.randint(0, 1), None)),
        0x6d0: _slot('ZFFActor', 0x6d0, 1)})
    c.emu.w32(actor, vt_actor)
    out = c.emu.fake_object('logger out', 0x40, vtable=c.emu.fake_vtable('PrintObj', 0x30 // 4 + 1, slots={
        0x2c: _slot('PrintObj', 0x2c, 3, log_ecx=False, pop=False)}))
    logger = c.emu.fake_object('logger', 0x40, vtable=c.emu.fake_vtable('Logger', 0x24 // 4 + 1, slots={
        0x20: _slot('Logger', 0x20, 2, lambda e, a: (out, None), pop=True)}))
    c.emu.w32(0x700390, logger)
    return [actor, c.rng.choice([0, 1, c.rng.getrandbits(32)])]


S(0x5a2370, 'ZFFActor::PullWeapon (unknown)', 'thiscall', None, ret=None, gen=_pull,
  note='unclaimed-08 batch 3; field +0x78e or +0x78a; log path when zero; 0x4cbec0 original')
