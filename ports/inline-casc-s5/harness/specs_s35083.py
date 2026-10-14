"""specs_s35083.py - 0x425250 (cdecl(unused, fmt, va0, va1, va2), ret=None; the function ends in exit(-1)). The exit import is a Python stub that logs and ends the run as a return to the harness (unwind to the return slot, sentinel registers restored), so both versions end at the
same point; MessageBoxA is a Python stub (stdcall, four args, the text is read as a C string). 0x42abee hooked (cdecl, 3 args; writes a fixed text into the buffer, logs fmt and the first two variable-argument dwords);
logger at 0x700390 (slot 0x20 -> object with slot 0x2c, 3 args, caller-popped, a custom stub that logs the buffer's text instead of its stack address; slot 0x44 returns false, with garbage upper bytes: true would hit int3); engine object slots 0x3c, 0x14 (0 args) and 0x5c (2 args, AL true in 1/3)."""
import pilot
import pe_emu
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g425250(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    txt = bytes(r.choice(b'abc XYZ09:') for _ in range(r.randint(0, 40))) + b'\0'

    def h(em, rr):
        em.calllog.append(('42abee', em.arg32(1), em.r32(em.arg32(2)), em.r32(em.arg32(2) + 4)))
        em.wbytes(em.arg32(0), txt)
        em.ret(eax=0)
    e.hook(0x42abee, h)

    def rdstr(em, p):
        s = b''
        while len(s) < 0x400:
            ch = bytes(em.rbytes(p + len(s), 1))
            if ch == b'\0':
                break
            s += ch
        return s

    def mbox(em, rr):
        em.calllog.append(('MessageBoxA', em.arg32(0), rdstr(em, em.arg32(1)), em.arg32(2), em.arg32(3)))
        em.ret(eax=1, argbytes=16)

    def ex(em, rr):
        em.calllog.append(('exit', em.arg32(0)))
        # end the call as if the function had returned: unwind to the harness return slot and restore the sentinel registers
        esp = em.reg('esp')
        while em.r32(esp) != em.RET_ADDR:
            esp += 4
        for k, v in pilot.SENTINELS.items():
            em.mu.reg_write(pe_emu.REGS[k], v)
        em.mu.reg_write(pe_emu.UC_X86_REG_EBP, pe_emu.STACK_TOP - 0x80)
        em.mu.reg_write(pe_emu.UC_X86_REG_ESP, esp + 4)
        em.mu.reg_write(pe_emu.UC_X86_REG_EIP, em.RET_ADDR)
    e.stub_import('MessageBoxA', mbox)
    e.stub_import('exit', ex)
    def l2c(em, rr):
        em.calllog.append(('slot2c', em.reg('ecx'), em.arg32(0), em.arg32(1), rdstr(em, em.arg32(2))))
        em.ret(eax=0)
    lg2 = obj(c, 0x20, {0x2c: e.stub_fn('slot2c', l2c)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True), 0x44: pystub(c, 0, this=True, ret=(r.getrandbits(24) << 8))}, nslots=0x20)
    e.w32(0x700390, lg)
    al = ((r.getrandbits(24) << 8) | r.choice([1, 2, 0x80])) if r.random() < 1 / 3 else (r.getrandbits(24) << 8)
    sysobj(c, slots={0x3c: pystub(c, 0, this=True), 0x14: pystub(c, 0, this=True), 0x5c: pystub(c, 2, this=True, ret=al)})
    fmt = rnd(c, 0x20)
    e.wbytes(fmt, bytes(r.choice(b'abc%d') for _ in range(r.randint(0, 12))) + b'\0')
    return [r.getrandbits(32), fmt, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x425250, 'GUESS fatal error report', 'cdecl', None, ret=None, gen=_g425250, note='batch35083')
